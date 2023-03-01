function obj = Get_Fr_dd( obj )
D=obj.D; T=obj.T;
obj.fr_dd=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
coef_3=obj.coef_gauss;
coef_4=obj.coef_nonanalitic;
for n=1:obj.n_coef_pol;
    obj.fr_dd=obj.fr_dd+(coef_1(n,3)*coef_1(n,1)*(coef_1(n,1)-1)*D^(coef_1(n,1)-2)*T^coef_1(n,2));
end
for n=1:obj.n_coef_exp;
    obj.fr_dd=obj.fr_dd+(coef_2(n,4)*D^(coef_2(n,2)-2)*T^coef_2(n,3)*obj.e^(-D^coef_2(n,1))*((coef_2(n,2)-coef_2(n,1)*D^coef_2(n,1))*(coef_2(n,2)-1-coef_2(n,1)*D^coef_2(n,1))-coef_2(n,1)^2*D^coef_2(n,1)));
end
for n=1:obj.n_coef_gauss;
    a=(coef_3(n,3)*T^coef_3(n,2));
    b=(obj.e^((-coef_3(n,4)*((D-coef_3(n,7))^2)-coef_3(n,5)*((T-coef_3(n,6))^2))));
    c=(-2*coef_3(n,4)*D^coef_3(n,1)+4*coef_3(n,4)^2*D^coef_3(n,1)*(D-coef_3(n,7))^2);
    d=(-4*coef_3(n,1)*coef_3(n,4)*D^(coef_3(n,1)-1)*(D-coef_3(n,7))+coef_3(n,1)*(coef_3(n,1)-1)*D^(coef_3(n,1)-2));
    obj.fr_dd=obj.fr_dd+a*b*(c+d);
end
for n=1:obj.n_coef_nonanalitic;
   fi=(1-T)+coef_4(n,7)*(((D-1)^2)^(1/(2*coef_4(n,8))));
    delta=fi^2+coef_4(n,3)*(((D-1)^2)^coef_4(n,1));
    delta_d=(D-1)*(coef_4(n,7)*fi*(2/coef_4(n,8))*((D-1)^2)^(1/(2*coef_4(n,8))-1)+2*coef_4(n,3)*coef_4(n,1)*((D-1)^2)^(coef_4(n,1)-1));
    deltab_d=coef_4(n,2)*(delta^(coef_4(n,2)-1))*delta_d;
    ex=obj.e^(-((coef_4(n,5)*((D-1)^2))+(coef_4(n,6)*((T-1)^2))));
    ex_d=-2*coef_4(n,5)*(D-1)*ex;
    ex_dd=(2*coef_4(n,5)*(D-1)^2-1)*2*coef_4(n,5)*ex;
    delta_dd=(1/(D-1))*delta_d+(D-1)^2*4*coef_4(n,3)*coef_4(n,1)*(coef_4(n,1)-1)*((D-1)^2)^(coef_4(n,1)-2);   
    delta_dd=delta_dd+(D-1)^2*2*coef_4(n,7)^2*(1/coef_4(n,8))^2*(((D-1)^2)^((1/(2*coef_4(n,8)))-1))^2;
    delta_dd=delta_dd+(D-1)^2*coef_4(n,7)*fi*(4/coef_4(n,8))*((1/(2*coef_4(n,8)))-1)*(((D-1)^2)^((1/(2*coef_4(n,8)))-2));
    deltab_dd=coef_4(n,2)*(delta^(coef_4(n,2)-1)*delta_dd+(coef_4(n,2)-1)*delta^(coef_4(n,2)-2)*delta_d^2);

   

    a=delta^coef_4(n,2)*(2*ex_d+D*ex_dd);
    b=2*deltab_d*(ex+D*ex_d);
    c=deltab_dd*D*ex;
    obj.fr_dd=obj.fr_dd+coef_4(n,4)*(a+b+c);
    

    
end
end

