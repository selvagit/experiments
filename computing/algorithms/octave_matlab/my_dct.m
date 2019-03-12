

N = 16;

ar_t = [0:1/(N-1):1];
ar_f = sin(2*pi*2*ar_t);

ar_cons =[1/1.414,ones(1,N-1)];

ar_F = zeros(1,N);

for u=1:N
    for i = 1:N
        ar_F(u) = ar_F(u) + ar_cons(i)*cos((2*i+1)*u*pi/(2*N))*ar_f(i);
    endfor
    
    ar_F(u) = ar_F(u)*sqrt(2/N);
endfor

