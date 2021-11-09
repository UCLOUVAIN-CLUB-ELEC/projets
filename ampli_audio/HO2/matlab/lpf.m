% Script to plot a LPF Bode diagram

clear all; close all;

% Frequency
f = logspace(1,6,1000);
omega = 2*pi*f;

% Filter components
C = 100e-9;
R = 1.6e3;

% Transfer function
H = 1./(1 + 1i*omega*R*C);

% Plot parameters
linewidth = 2;
labelsize = 16;
axissize = 13;

% Figures
figure('pos', [50 50 850 650]);
subplot(2,1,1);
plot(f, 20*log10(H), 'linewidth', linewidth); hold on;
plot([1e3 1e3], [-80 0], 'linewidth', linewidth, 'color', 'r'); grid on;
xlabel('f [Hz]', 'interpreter', 'latex', 'fontsize', labelsize);
ylabel('$20 \log_{10} \left(\frac{V_{out}}{V_{in}}\right)$ [dB]', 'interpreter', 'latex', 'fontsize', labelsize);
set(gca, 'xscale', 'log', 'fontsize', axissize);

subplot(2,1,2);
plot(f, angle(H)*180/pi, 'linewidth', linewidth); hold on;
plot([1e3 1e3], [-100 0], 'linewidth', linewidth, 'color', 'r'); grid on;
xlabel('f [Hz]', 'interpreter', 'latex', 'fontsize', labelsize);
ylabel('$\arg \left(\frac{V_{out}}{V_{in}}\right)$ [$^\circ$]', 'interpreter', 'latex', 'fontsize', labelsize);
set(gca, 'xscale', 'log', 'fontsize', axissize);