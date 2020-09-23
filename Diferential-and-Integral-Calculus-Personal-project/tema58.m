function task58
clf
tmax=8;
t=linspace(0,tmax);
xmax=10*pi;
x=linspace(0,xmax);
    function y=phi(x)
        for i=1:length(x)
            if x(i)>=(2*pi) && x(i)<=(6*pi)
                y(i)=(1+cos(x(i)/2))^3;
            else
                y(i)=0;
            end
        end
    end
        function y=psi(x)
            y=sin(x);
        end
    function y=phi_even(x)
        if x>=0
            y=phi(x);
        else
            y=phi(-x);
        end

    end
        function y=psi_even(x)
            for n=1:length(x) 
                if x(n)>=0
                    y(n)=psi(x(n));
                else
                    y(n)=psi(-x(n));
                end
            end
        end
    function y=dalambert(x,t)
    a=sqrt(2/(pi^2));
        for j=1:length(x)
            if t==0
                integral=0;
            else
                s=linspace(x(j)-a*t,x(j)+a*t);
                integral=trapz(s,psi_even(s));
            end
            y(j)=(phi_even(x(j)-a*t)+phi_even(x(j)+a*t))/2+integral/(2*a);
        end
    end
    for k=1:length(t)
        clf
        hold on
        plot(x,dalambert(x,t(k)),'r','Linewidth',2)
        plot(0,0,'ko','MarkerFaceColor',[0,0,0])
        axis ([0,xmax,-10,10])
        grid on
        %daspect([1,1,1])
        xlabel('x')
        ylabel('u(x,t)')
        M=getframe;
    end
    
subplot(3,1,1)
plot(x,dalambert(x,0),'r','Linewidth',2)
title('t=0');
hold on
subplot(3,1,2)
plot(x,dalambert(x,3),'r','Linewidth',2)
title('t=3');
hold on
subplot(3,1,3)
plot(x,dalambert(x,tmax),'r','Linewidth',2)
title(['t=', num2str(tmax)]);
hold on

end

