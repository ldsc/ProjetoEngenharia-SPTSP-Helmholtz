function obj = Get_Fr_ddt( obj )
D=obj.D; T=obj.T;
obj.fr_ddt=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
coef_3=obj.coef_gauss;
coef_4=obj.coef_nonanalitic;
for n=1:obj.n_coef_pol;
    obj.fr_ddt=obj.fr_ddt+(coef_1(n,3)*coef_1(n,1)*(coef_1(n,1)-1)*D^(coef_1(n,1)-2)*coef_1(n,2)*T^(coef_1(n,2)-1));
end
for n=1:obj.n_coef_exp;
    obj.fr_ddt=obj.fr_ddt+(coef_2(n,4)*D^(coef_2(n,2)-2)*coef_2(n,3)*T^(coef_2(n,3)-1)*obj.e^(-D^coef_2(n,1))*((coef_2(n,2)-coef_2(n,1)*D^coef_2(n,1))*(coef_2(n,2)-1-coef_2(n,1)*D^coef_2(n,1))-coef_2(n,1)^2*D^coef_2(n,1)));
end
for n=1:obj.n_coef_gauss;
    a=(coef_3(n,3)*T^coef_3(n,2));
    b=(obj.e^((-coef_3(n,4)*((D-coef_3(n,7))^2)-coef_3(n,5)*((T-coef_3(n,6))^2))));
    c=(-2*coef_3(n,4)*D^coef_3(n,1)+4*coef_3(n,4)^2*D^coef_3(n,1)*(D-coef_3(n,7))^2);
    d=(-4*coef_3(n,1)*coef_3(n,4)*D^(coef_3(n,1)-1)*(D-coef_3(n,7))+coef_3(n,1)*(coef_3(n,1)-1)*D^(coef_3(n,1)-2));
    e=((coef_3(n,2)/T)-2*coef_3(n,5)*(T-coef_3(n,6)));
    obj.fr_ddt=obj.fr_ddt+a*b*e*(c+d);
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
    deltab_t=-2*fi*coef_4(n,2)*(delta^(coef_4(n,2)-1));
    deltab_dt=-coef_4(n,7)*coef_4(n,2)*(2/coef_4(n,8))*(delta^(coef_4(n,2)-1))*(D-1)*((D-1)^2)^(1/(2*coef_4(n,8))-1)-2*fi*coef_4(n,2)*(coef_4(n,2)-1)*(delta^(coef_4(n,2)-2))*delta_d;
    delta_dt=(1-D)*(0.64/0.3)*((D-1)^2)^(1/0.6-1); 
    delta_ddt=delta_dt/(D-1)-(D-1)^2*coef_4(n,7)*(4/coef_4(n,8))*(1/(2*coef_4(n,8))-1)*((D-1)^2)^(1/(2*coef_4(n,8))-2);    
    deltab_ddt=coef_4(n,2)*(delta_ddt*delta^(coef_4(n,2)-1)-2*fi*(coef_4(n,2)-1)*delta^(coef_4(n,2)-2)*delta_dd+(coef_4(n,2)-1)*delta^(coef_4(n,2)-2)*2*delta_dt*delta_d-2*fi*(coef_4(n,2)-2)*(coef_4(n,2)-1)*delta^(coef_4(n,2)-3)*delta_d*delta_d); 
    ex_t=-2*coef_4(n,6)*(T-1)*ex;
    ex_dt=(4*coef_4(n,5)*coef_4(n,6)*(D-1)*(T-1)*ex);
    ex_ddt=-4*coef_4(n,6)*coef_4(n,5)*(T-1)*(2*coef_4(n,5)*(D-1)^2-1)*ex;
    
    
    a=delta^coef_4(n,5)*(2*ex_dt+D*ex_ddt);
    b=deltab_t*(2*ex_d+D*ex_dd);
    c=2*deltab_d*(ex_t+D*ex_dt);
    d=2*deltab_dt*(ex+D*ex_d);
    e=deltab_dd*D*ex_t;
    f=deltab_ddt*D*ex;
    obj.fr_ddt=obj.fr_ddt+coef_4(n,4)*(a+b+c+d+e+f);
    

    
end
end

