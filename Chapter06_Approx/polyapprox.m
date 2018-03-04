set(0,'defaultaxeslinewidth',1.5);
set(0,'defaultaxesfontsize',26);

%wysiwyg;
n=11  % use n=11 for figure

clf;
x=[-1:2/(n-1):1];
xx=[-1:0.01:1];
f=1./(1+25*x.^2);
ff=1./(1+25*xx.^2);
[p,s]=polyfit(x,f,n-1);
hold on
h1=plot(x,f,'ko','markerfacecolor','k','markersize',8);
plot(xx,ff,'k--','linewidth',1.5);
plot(xx,polyval(p,xx),'k-','linewidth',2);
hold off
box on
xlabel('x','fontangle','italic')
ylabel('f(x)','fontangle','italic')



% set(gca,'position',[0.15    0.12    0.7750    0.8150])
% print -deps polyappr.eps
