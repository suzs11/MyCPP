clear all;
clc;
load Loren
Leakingrate=0.2;
nL=length(Leakingrate);
Ydata(:,1)=Y(1000:42000,1)./max(abs(Y(1000:42000,1)));
Ydata(:,2)=Y(1000:42000,2)./max(abs(Y(1000:42000,2)));
Ydata(:,3)=Y(1000:42000,3)./max(abs(Y(1000:42000,3)));
for k=1:nL
indata=Ydata;
outdata=Ydata;
initLen = 100;
trainLen =2600;
testLen = 600;
density=0.25;
inSize = 3; 
outSize = 3;
resSize =500; % size of the reservoir nodes;
a =Leakingrate(k); % leaking rate
Win = 2.0*rand(resSize,1+inSize)-1.0;
W=sprand(resSize, resSize, density);  
disp 'Computing spectral radius...';
opt.disp = 0;
rhoW = abs(eigs(W,1,'LM',opt));
disp 'done.'
W = W .* (0.95/rhoW); % the spectral radius is 1.25:
% allocated memory for the design (collected states) matrix
X = zeros(1+inSize+resSize,trainLen-initLen);
% set the corresponding target matrix directly
Yt = outdata(initLen+2:trainLen+1,:)';
% run the reservoir with the data and collect X
x = zeros(resSize,1);
for t = 1:trainLen
    u = indata(t,:)';
    x = (1-a)*x + a*tanh( Win*[1;u] + W*x );
    if t > initLen
        X(:,t-initLen) = [1;u;x];
    end
end
reg = 1e-8;  % regularization coefficient
X_T = X';
% Wout = Yt*X_T * inv(X*X_T + reg*eye(1+inSize+resSize));
Wout = Yt*X_T / (X*X_T + reg*eye(1+inSize+resSize));
Y1= zeros(outSize,testLen);
u = indata(trainLen+1,:)';
for t = 1:testLen 
    x = (1-a)*x + a*tanh( Win*[1;u] + W*x );
    y = Wout*[1;u;x];
    Y1(:,t) = y;
    % generative mode:
    u = y;
end
end
figure(1);
plot( outdata(trainLen+2:trainLen+testLen+1,1),'linewidth',2);
hold on;
plot( Y1(1,:)','-- ','linewidth',2);
hold off;
axis tight;
% figure(2);
% plot( outdata(trainLen+2:trainLen+testLen+1,2),'linewidth',2);
% hold on;
% plot( Y1(2,:)','-- ','linewidth',2);
% hold off;
% axis tight;
% figure(3);
% plot( outdata(trainLen+2:trainLen+testLen+1,3),'linewidth',2);
% hold on;
% plot( Y1(3,:)','-- ','linewidth',2);
% hold off;
% axis tight;
%title('Target and generated signals y(n) starting at n=0');
% legend('Actual signal', 'Reservior output');
% xlabel('\it{t-T}','FontName','Times New Roman','FontSize',24);
% ylabel('\it{output}','FontName','Times New Roman','FontSize',24);
number=10000;
Ydata=zeros(number,3);
Pdata=zeros(number,3);
Pdata1=zeros(number,3);
x1=x;
u1=[1 0 0.1]';
u=[-1 0.5 1]';
%Initial=outdata(trainLen+2,:);%.*[max(abs(Y(1000:11000,1))) max(abs(Y(1000:11000,2))) max(abs(Y(1000:11000,3)))];
%u(1)=indata(trainLen+2,1);
for i=1:number;
   u(1)=indata(trainLen+1+i,1);
   u1(2)=u(2);
   x = (1-a)*x + a*tanh( Win*[1;u] + W*x );
   y = Wout*[1;u;x];
   Pdata(i,:) = y;
   u=y;
   x1 = (1-a)*x1 + a*tanh( Win*[1;u1] + W*x1 );
   y1 = Wout*[1;u1;x1];
   Pdata1(i,:) = y1;
   u1=y1;
end;

time=[1:number]*0.02;
figure(4);
plot(time,outdata(trainLen+3:trainLen+2+number,1),'linewidth',2);
hold on;
plot(time,Pdata1(:,1)','-- ','linewidth',2);
hold off;
axis tight;
xlabel('\it{t}','FontName','Times New Roman','FontSize',26);
ylabel('\it{x(t)}','FontName','Times New Roman','FontSize',26);

figure(5);
plot(time,outdata(trainLen+3:trainLen+2+number,3),'linewidth',2);
hold on
plot(time,Pdata(:,3),'-- ','linewidth',2);
hold on
plot(time,Pdata1(:,3),'-.','linewidth',2);
hold off;
xlabel('\it{t}','FontName','Times New Roman','FontSize',26);
ylabel('\it{z(t)}','FontName','Times New Roman','FontSize',26);
% figure(6);
% plot( outdata(trainLen+3:trainLen+2+number,3)-Pdata(:,3),'linewidth',2);
% figure(2);
% plot( X(1:20,1:200)' );
% title('Some reservoir activations x(n)');
% 
% figure(3);
% bar( Wout' )
% title('Output weights W^{out}');