function obj = Get_Fr_dt( obj )
% Normal residual part
D=obj.D; T=obj.T;
obj.fr_dt=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
coef_3=obj.coef_gauss;
coef_4=obj.coef_nonanalitic;
for n=1:obj.n_coef_pol;
    obj.fr_dt=obj.fr_dt+(coef_1(n,3)*coef_1(n,1)*coef_1(n,2)*D^(coef_1(n,1)-1)*T^(coef_1(n,2)-1));
end
for n=1:obj.n_coef_exp;
    obj.fr_dt=obj.fr_dt+(coef_2(n,4)*coef_2(n,3)*D^(coef_2(n,2)-1)*T^(coef_2(n,3)-1)*(coef_2(n,2)-coef_2(n,1)*D^coef_2(n,1))*obj.e^(-D^coef_2(n,1)));
end
for n=1:obj.n_coef_gauss;
    a=(coef_3(n,3)*D^coef_3(n,1)*T^coef_3(n,2));
    b=(obj.e^((-coef_3(n,4)*((D-coef_3(n,7))^2)-coef_3(n,5)*((T-coef_3(n,6))^2))));
    c=((coef_3(n,1)/D)-2*coef_3(n,4)*(D-coef_3(n,7)));
    d=((coef_3(n,2)/T)-2*coef_3(n,5)*(T-coef_3(n,6)));
    obj.fr_dt=obj.fr_dt+a*b*c*d;
end
for n=1:obj.n_coef_nonanalitic;
    fi=(1-T)+coef_4(n,7)*(((D-1)^2)^(1/(2*coef_4(n,8))));
    delta=fi^2+coef_4(n,3)*(((D-1)^2)^coef_4(n,1));
    delta_d=(D-1)*(coef_4(n,7)*fi*(2/coef_4(n,8))*((D-1)^2)^(1/(2*coef_4(n,8))-1)+2*coef_4(n,3)*coef_4(n,1)*((D-1)^2)^(coef_4(n,1)-1));
    deltab_d=coef_4(n,2)*(delta^(coef_4(n,2)-1))*delta_d;
    ex=obj.e^(-((coef_4(n,5)*((D-1)^2))+(coef_4(n,6)*((T-1)^2))));
    ex_d=-2*coef_4(n,5)*(D-1)*ex;
    deltab_t=-2*fi*coef_4(n,2)*(delta^(coef_4(n,2)-1));
    deltab_dt=-coef_4(n,7)*coef_4(n,2)*(2/coef_4(n,8))*(delta^(coef_4(n,2)-1))*(D-1)*((D-1)^2)^(1/(2*coef_4(n,8))-1)-2*fi*coef_4(n,2)*(coef_4(n,2)-1)*(delta^(coef_4(n,2)-2))*delta_d;
    ex_t=-2*coef_4(n,6)*(T-1)*ex;
    ex_dt=(4*coef_4(n,5)*coef_4(n,6)*(D-1)*(T-1)*ex);

    
    obj.fr_dt=obj.fr_dt+coef_4(n,4)*(delta^coef_4(n,2))*(ex_t+D*ex_dt);
    obj.fr_dt=obj.fr_dt+coef_4(n,4)*(D*deltab_d*ex_t);
    obj.fr_dt=obj.fr_dt+coef_4(n,4)*(deltab_t*(ex+D*ex_d));
    obj.fr_dt=obj.fr_dt+coef_4(n,4)*(deltab_dt*D*ex);
end
end

