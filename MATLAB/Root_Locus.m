% ------------------------------------------------------------
% Name: root_locus.m
% Desc: Root Locus Plot
% Vers: Nov 16, 2022, jrm, beautified
%       Nov  2, 2022, jrm, original
%       Dec  4, 2022, zc,  modified 
%
% ------------------------------------------------------------

close all;
clear all;
format compact;

% ------------------------------------------------------------

%
% Start with
%
%   G(s) = 1 / ( 1 s^3 + 8 s^2 + 24 s + 32 );
%
% which has Open Loop Poles at 
%   -4, -2+2i, and -2-2i.
%

% The first thing done was adding a controls system tool
% box to MATLAB so that the function tf can plot 
% root locus plots 
% The revision made was changing the my_den to 
% match the denominator given in the problem so that 
% the MATLAB code matched the given plant transfer fucntion of 
% G(s) = 1 / ( 1 s^3 + 13 s^2 + 32 s + 20 ); 
% where the function would have no open loop zeros 
% and open loop poles at -10,-2, and -1
% The revision was shown in line 41 while line 37 kept the my_num since 
% the problem had one as the numerator 

my_num = [1];

%my_den = [1 8 24 32];

my_den = [1 13 32 20];

%
% Show the Open Loop Poles and Zeros
%

my_zeros = roots( my_num );
disp( 'Open Loop Zeros' );
disp( my_zeros );

my_poles = roots( my_den );
disp('Open Loop Poles');
disp( my_poles );

%
% Now, place the system into a closed loop,
% feedback system with variable gain, K
% And compute a Root Locus Plot.
%
% The original Pole locations ('X')
% show what happens with a loop gain of Zero.
%
% The poles wander a path that shows what happens
% when the gain is progressively turned up.
%
% Notice that at some gain, some pole wander across
% the imaginary axis into the right-half plane,
% indicating that there is some gain that will
% drive the system un-stable.
%
% The Closed-Loop System:
%
%  R(s) --> (sum) ---> G(s) ->-+---> C(s)
%         +   ^ -              |
%             |                |
%             +----<--- K <----+
%

clear tf
my_sys = tf( my_num, my_den );

rlocus( my_sys );

% ------------------------------------------------------------
% ------------------------------------------------------------
