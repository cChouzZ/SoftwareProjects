% ------------------------------------------------------------
% Name: pid_control.m
% Desc: PID Control Time Plot
% Vers: Nov 16, 2022, jrm, beautified
%       Sep 28, 2022, jrm, original
%       Dec 4,  2022, zc, modified 
% ------------------------------------------------------------

close all;
clear all;
format compact;

% ------------------------------
%
% Set up time, set point, and output arrays
%

Ts = 0.001; % Sampling time (seconds)
Tmax = 10.0; % Max time (seconds)

N = floor(Tmax/Ts);

t = Ts*(0:(N-1)); % time

sp = (t>=1.0); % set point samples = step function

cmd = zeros(size(t)); % command values

x = zeros(size(t)); % output samples


% ------------------------------
%
% PID Controller constants
%

Kp = 2.0;
% Changed to Kp = 4.0
% Changed to Kp = 6.0 
% Changed to Kp = 8.0
% Changed to Kp = 10.0
Ki = 0.0;
Kd = 0.0;

% controller variables
err = 0;
err_int = 0;
err_dif = 0;


% ------------------------------
%
% Plant model
%
%              ( Gn1 s + Gn0 )
% G(s) = -------------------------------
%        ( s^3 + Gd2 s^2 + Gd1 s + Gd0 )
%

% Transfer function constants
% Gn1 = 32.0;
% Gn0 = 32.0;
% Gd2 =  8.0;
% Gd1 = 24.0;
% Gd0 = 32.0;

% ------------------------------
%
% Plant model from Homework 8 
%
%                    1 
% G(s) = -------------------------------
%        ( s^3 + 13 s^2 + 32 s + 20 )
%

% Transfer function constants
% Line 75 is 0 becasue Gn1 will have an s for which the homework does 
% not have an s on the numerator, only a number on the numerator 
Gn1 = 0.0; 
Gn0 = 1.0;
Gd2 = 13.0;
Gd1 = 32.0;
Gd0 = 20.0;


% state vars
sv1 = 0;
sv2 = 0;
sv3 = 0;

% ------------------------------
%
% Simulate the closed loop in the time domain
%

for ii=(1:(N-1))

    % ------------------------------
    % Controller

    err_old = err;

    % Error
    err = sp(ii) - x(ii);

    % Error Integral
    err_int = err_int + ( Ts * err );

    % Error Differential
    err_dif = ( err - err_old ) / Ts;

    % Controller Command
    command = (Kp * err) ...
            + (Ki * err_int) ...
            + (Kd * err_dif);

    cmd(ii) = command;

    % ------------------------------
    % Plant

    sv3_add = ( command ) ...
            - ( Gd2 * sv3 ) ...
            - ( Gd1 * sv2 ) ...
            - ( Gd0 * sv1 );

    % Integrate the State Variables
    sv3_new = sv3 + Ts * sv3_add;
    sv2_new = sv2 + Ts * sv3;
    sv1_new = sv1 + Ts * sv2;

    sv3 = sv3_new;
    sv2 = sv2_new;
    sv1 = sv1_new;

    % Output of plant

    x(ii+1) = (Gn0 * sv1) + (Gn1 * sv2);

end % ii


% ------------------------------
%
% Plot the time response
%

figure;
subplot( 2, 1, 1 );
plot( t, sp, t, x );
title( 'Setpoint vs Time and Output vs Time' );

subplot( 2, 1, 2 );
plot( t, cmd );
title( 'Command vs Time' );


% ------------------------------------------------------------
% ------------------------------------------------------------
