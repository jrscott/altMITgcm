function [uE,vN] = rotate_csCg_EN(u,v)
% [uE,vN] = rotate_csCg_EN(u,v)
%
% Rotate U,V vector components of cs-grid (C-grid) to East,North direction
%  u,v   is a 2-D or 3-D horizontal components of model flow fields.
%  uE,vN are the component of the rotated flow field
% assume that the 1rst 2 dimensions of (u,v) are [6*nc nc] for a CS(nc x nc) grid
%
% >> u=rdmds('uVeltave.0000513360');
% >> v=rdmds('vVeltave.0000513360');
% >> [uE,vN]=rotate_csCg_EN(u,v);
%
% $Header: /u/gcmpack/MITgcm/utils/cs_grid/Attic/rotate_csCg_EN.m,v 1.1 2005/06/28 02:34:54 jmc Exp $

%Rac='/home/jmc/grid_cs32/' ;
Rac='grid_files/';

NN=size(u);
if length(NN) < 3, nz=1; [nnx nc]=size(u); else [nnx nc nz]=size(u); end
nPg=nnx*nc;

if nnx ~= 6*nc,
 fprintf('Error in CS-dim: %i %i %i \n',NN);
 uE=zeros(NN); vN=zeros(NN);
 return
end

u=reshape(u,[nnx nc nz]);
v=reshape(v,[nnx nc nz]);

%- do simple average to put u,v at the center (A-grid):
[uu,vv] = split_UV_cub(u,v);

u=(uu(1:nc,:,:,:)+uu(2:nc+1,:,:,:))/2;
v=(vv(:,1:nc,:,:)+vv(:,2:nc+1,:,:))/2;

u=reshape(permute(u,[1 4 2 3]),[nPg nz]);
v=reshape(permute(v,[1 4 2 3]),[nPg nz]);

%- rotate toward E,N (lon,lat) directions :
% load COS & SIN of rotation angle:
namfil=['proj_cs',int2str(nc),'_2uEvN.bin'];
fid=fopen([Rac,namfil],'r','b'); uvEN=fread(fid,nPg*2,'real*8'); fclose(fid);
uvEN=reshape(uvEN,[nPg 2]);

uE=zeros(nPg,nz); vN=zeros(nPg,nz);
for k=1:nz;
 uE(:,k)=uvEN(:,1).*u(:,k)-uvEN(:,2).*v(:,k);
 vN(:,k)=uvEN(:,2).*u(:,k)+uvEN(:,1).*v(:,k);
end

uE=reshape(uE,[nnx NN(2:end)]);
vN=reshape(vN,[nnx NN(2:end)]);

return
