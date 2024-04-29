%% Monte Carlo Current Mirror Analysis with vectors 

clc;
clear all;
close all;

N = 25000; % Number of data points
rng default

% Preallocate arrays for parameters and results
params = zeros(N, 7);
results = zeros(N, 3);

% Other nomial values for the circuit
% Lambda (Lambda) 
Lambda = 0.001;

% Kpn (Kpn)
Kpn_tolerance = 0.5; % 50 percent tolerance
Kpn = 0.12e-3*(1 + 2*Kpn_tolerance*(rand(1, N) - 0.5));

% Variables for Monte Carlo Analysis
% W1
W1_nom = 10;
W1_tolerance = 0.5; % 50 percent tolerance  

% rng default
W1 = W1_nom*(1 + 2*W1_tolerance*(rand(1,N) - 0.5));
W1_mean = mean(W1);
W1_std = std(W1);

% W2
W2_nom = 10;
W2_tolerance = 0.5; % 50 percent tolerance  

% rng default
W2 = W2_nom*(1 + 2*W2_tolerance*(rand(1,N) - 0.5));
W2_mean = mean(W2);
W2_std = std(W2);

% L1
L1_nom = 2;
L1_tolerance = 0.5; % 50 percent tolerance  

% rng default
L1 = L1_nom*(1 + 2*L1_tolerance*(rand(1,N) - 0.5));
L1_mean = mean(L1);
L1_std = std(L1);

% L2
L2_nom = 2;
L2_tolerance = 0.5; % 50 percent tolerance  

% rng default
L2 = L2_nom*(1 + 2*L2_tolerance*(rand(1,N) - 0.5));
L2_mean = mean(L2);
L2_std = std(L2);

% Rd
Rd_nom = 20e3; % 20k
Rd_tolerance = 0.5; % 50 percent tolerance  

% rng default
Rd = Rd_nom*(1 + 2*Rd_tolerance*(rand(1,N) - 0.5));
Rd_mean = mean(Rd);
Rd_std = std(Rd);

% Vth
Vth_nom = 1;
Vth_tolerance = 0.2; % 20 percent tolerance  

% rng default
Vth = Vth_nom*(1 + 2*Vth_tolerance*(rand(1,N) - 0.5));
Vth_mean = mean(Vth);
Vth_std = std(Vth);

% Vdd
Vdd_nom = 5;
Vdd_tolerance = 0.5; % 50 percent tolerance  

% rng default
Vdd = Vdd_nom*(1 + 2*Vdd_tolerance*(rand(1,N) - 0.5));
Vdd_mean = mean(Vdd);
Vdd_std = std(Vdd);

% Formulas for other variables, I_ref and IO

% For the left side of the current mirror
Iref = 10e-6;
Iref_tolerance = 0.5; % 50 percent tolerance
I_ref = Iref*(1 + 2*Iref_tolerance*(rand(1, N) - 0.5));
I_ref_mean = mean(I_ref);
I_ref_std = std(I_ref);

% Voltage gate-source equation, Vgs1
Vgs = sqrt(2*I_ref./(Kpn.*(W1./L1))) + Vth;

% Voltage drain-source equation, Vds1
Vds1 = Vgs;

% I0 load current calculation
K = Kpn/2.*(W2./L2).*(Vgs - Vth).^2;
I0 = K.*(1 + Lambda.*Vdd)./(1 + Lambda.*K.*Rd); 
% where K = Kpn/2*(W2/L2)*(Vgs - Vth)^2
I0_mean = mean(I0);
I0_std = std(I0);

% Mirror Ratio, MR
 MR = I0./I_ref;
 MR_mean = mean(MR);
 MR_std = std(MR);

 %% Convert each variable and array to a cell array
W1Cell = num2cell(W1);
W2Cell = num2cell(W2);
L1Cell = num2cell(L1);
L2Cell = num2cell(L2);
RdCell = num2cell(Rd);
VthCell = num2cell(Vth);
VddCell = num2cell(Vdd);
I_refCell = num2cell(I_ref);
I0Cell = num2cell(I0);
MRCell = num2cell(MR);

%% Concatenate all cell arrays vertically
dataCell = [W1Cell; W2Cell; L1Cell; L2Cell; RdCell; VthCell; VddCell; I_refCell; I0Cell; MRCell]';

% Add column labels 
columnLabels = {'W1', 'W2', 'L1', 'L2', 'Rd', 'Vth', 'Vdd', 'I_ref', 'I0', 'MR'};

% Concatenate the column labels with the data cell array
dataCell = [columnLabels; dataCell];

% Write the cell array to an Excel file
writecell(dataCell, 'CurrentMirrorData1.xlsx');

%% Graphs for gaussian normal distribution
figure(1)
hist(W1,20);
title("''W1 - 25000 Iterations''" + " (" + "Mean: " + W1_mean + ", SD: " + W1_std + ")");
xlabel('W1');
ylabel('Frequency');

figure(2)
hist(W2,20);
title("''W2 - 25000 Iterations''" + " (" + "Mean: " + W2_mean + ", SD: " + W2_std + ")");
xlabel('W2');
ylabel('Frequency');

figure(3)
hist(L1,20);
title("''L1 - 25000 Iterations''" + " (" + "Mean: " + L1_mean + ", SD: " + L1_std + ")");
xlabel('L1');
ylabel('Frequency');

figure(4)
hist(L2,20);
title("''L2 - 25000 Iterations''" + " (" + "Mean: " + L2_mean + ", SD: " + L2_std + ")");
xlabel('L2');
ylabel('Frequency');

figure(5)
hist(Rd,20);
title("''Rd - 25000 Iterations''" + " (" + "Mean: " + Rd_mean + ", SD: " + Rd_std + ")");
xlabel('Rd');
ylabel('Frequency');

figure(6)
hist(Vth,20);
title("''Vth - 25000 Iterations''" + " (" + "Mean: " + Vth_mean + ", SD: " + Vth_std + ")");
xlabel('Vth');
ylabel('Frequency');

figure(7)
hist(Vdd,20);
title("''Vdd - 25000 Iterations''" + " (" + "Mean: " + Vdd_mean + ", SD: " + Vdd_std + ")");
xlabel('Vdd');
ylabel('Frequency');

figure(8)
hist(I0,20);
title("''I0 - 25000 Iterations''" + " (" + "Mean: " + I0_mean + ", SD: " + I0_std + ")");
xlabel('I0');
ylabel('Frequency');

figure(9)
hist(I_ref,20);
title("''I_ref - 25000 Iterations''" + " (" + "Mean: " + I_ref_mean + ", SD: " + I_ref_std + ")");
xlabel('I_ref');
ylabel('Frequency');

figure(10)
hist(MR,20);
title("''MR - 25000 Iterations''" + " (" + "Mean: " + MR_mean + ", SD: " + MR_std + ")");
xlabel('MR');
ylabel('Frequency');

