#pkg unload control 
pkg load optim

## Charge
c5 = [12.6, 12.77, 12.95, 13.2, 13.39, 13.53, 13.675, 14.02, 15.27, 15.96, 16.25, 16.38];
c10 = [12.38, 12.6, 12.82, 13.05, 13.2, 13.3, 13.41, 13.63, 14.08, 15.24, 15.72, 15.95];
c20 = [12.05, 12.42, 12.69, 12.89, 13.015, 13.12, 13.18, 13.3, 13.58, 14.15, 15.17, 15.54];
c40 = [11.8, 12.25, 12.55, 12.72, 12.82, 12.92, 12.95, 13.0, 13.15, 13.5, 14.5, 15.08];

## Rest
rest = [11.7, 11.915, 12.115, 12.24, 12.32, 12.415, 12.5, 12.6, 12.59, 12.61];

## Discharge
d100 = [12.66, 12.66, 12.64, 12.605, 12.54, 12.48, 12.38, 12.28, 12.12, 11.925, 11.7];
d20 = [12.604, 12.545, 12.54, 12.5, 12.42, 12.323, 12.22, 12.1, 11.915, 11.7, 11.45];
d10 = [12.485, 12.425, 12.35, 12.248, 12.13, 12.004, 11.88, 11.695, 11.48, 11.28, 11];
d5 = [12.065, 12.0, 11.917, 11.81, 11.69, 11.522, 11.385, 11.18, 10.91, 10.602, 10.2];
d3 = [11.78, 11.7, 11.61, 11.495, 11.325, 11.145, 10.98, 10.715, 10.39, 9.97, 9.48];

percent = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120];
percent11 = [110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10];
percentRest = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];

figure(1)
hold on
grid on
box on
#loglog(percent, c5, 'g<', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent, c5, 'b*', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent, c10, 'r*', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent, c20, 'g*', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent, c40, 'k*', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percentRest, rest, 'r<', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent11, d3, 'gs', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent11, d5, 'bs', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent11, d10, 'rs', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent11, d20, 'ro', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(percent11, d100, 'bo', 'LineWidth', 1, 'MarkerSize', 7.5)
ylabel("voltage")
xlabel("percentage charge")
 title ("Charge vs Voltage Plot");
 h = legend ({"C/5"}, "C/10", "C/20", "C/40", "rest");
 legend (h, "location", "northeastoutside");
 set (h, "fontsize", 14);
hold off

figure(2)
hold on
grid on
box on
#loglog(percent, c5, 'g<', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(c5, percent, 'b*', 'LineWidth', 1, 'MarkerSize', 7.5)
%plot(x,  (x - 17.481).* (x - 14.408).* (x - 14.202).* (x - 12.168).* (x - 17.452).* (x - 14.783) + 78.465, 'b-', 'LineWidth', 1, 'MarkerSize', 7.5)

plot(c10, percent, 'r*', 'LineWidth', 1, 'MarkerSize', 7.5)
%plot(x,  (x - 11.992).* (x - 14.325).* (x - 17.428).* (x - 14.420).* (x - 14.353).* (x - 17.227) + 88.222, 'r-', 'LineWidth', 1, 'MarkerSize', 7.5)

plot(c20, percent, 'g*', 'LineWidth', 1, 'MarkerSize', 7.5)
%plot(x,  (x - 17.190).* (x - 14.171).* (x - 14.205).* (x - 11.740).* (x - 17.159).* (x - 14.222) + 94.499)

plot(c40, percent, 'b<', 'LineWidth', 1, 'MarkerSize', 7.5)
%plot(x,  (x - 14.6659).* (x - 14.8680).* (x - 9.8940).* (x - 9.9535).* (x - 13.3392).* (x - 9.9839) + 100.1695)

plot(rest, percentRest, 'r<', 'LineWidth', 1, 'MarkerSize', 7.5)

plot(d3, percent11, 'gs', 'LineWidth', 1, 'MarkerSize', 7.5)
%plot(x,  (x - 10.1354).* (x - 10.1681).* (x - 10.1423).* (x - 6.4437).* (x - 13.7005).* (x - 13.5256) + 27.9198)

plot(d5, percent11, 'bs', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(d10, percent11, 'rs', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(d20, percent11, 'ro', 'LineWidth', 1, 'MarkerSize', 7.5)
plot(d100, percent11, 'bo', 'LineWidth', 1, 'MarkerSize', 7.5)
xlabel("voltage")
ylabel("percentage charge")
 title ("Voltage vs Charge Plot");
 h = legend ({"C/5"}, "C/5 Fit", "C/10", "C/10 Fit", "C/20", "C/20 Fit", "C/40", "C/40 Fit", "Rest");
 legend (h, "location", "northeastoutside");
 set (h, "fontsize", 14);
hold off