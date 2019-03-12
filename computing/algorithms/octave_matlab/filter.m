


figure();
[b,a] = butter(4,0.2,'low');
[h,z] = freqz(b,a);
norm_freq = [0:1/(512-1):1];
plot(norm_freq,abs(h));

[b_1,a_1] =  butter(1,0.2,'low');
[h_1,z_1] = freqz(b_1,a_1);
plot(abs(h_1));

G = 6;
fc = 300;
Q = 0.2; % fb/fc
fs = 8000;

[b_2,a_2] = peaking(G,fc,Q,fs);
[h_2,z_2] = freqz(b_2,a_2);
plot(norm_freq,abs(h_2));
