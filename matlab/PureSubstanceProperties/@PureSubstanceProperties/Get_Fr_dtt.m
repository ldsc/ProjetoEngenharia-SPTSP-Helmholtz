function obj = Get_Fr_dtt( obj )
% Normal residual part
D=obj.D; T=obj.T;
obj.fr_dtt=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
coef_3=obj.coef_gauss;
coef_4=obj.coef_nonanalitic;
for n=1:obj.n_coef_pol;
    obj.fr_dtt=obj.fr_dtt+(coef_1(n,3)*coef_1(n,1)*coef_1(n,2)*(coef_1(n,2)-1)*D^(coef_1(n,1)-1)*T^(coef_1(n,2)-2));
end
for n=1:obj.n_coef_exp;
    obj.fr_dtt=obj.fr_dtt+(coef_2(n,4)*coef_2(n,3)*(coef_2(n,3)-1)*D^(coef_2(n,2)-1)*T^(coef_2(n,3)-2)*(coef_2(n,2)-coef_2(n,1)*D^coef_2(n,1))*obj.e^(-D^coef_2(n,1)));
end
for n=1:obj.n_coef_gauss;
    a=(coef_3(n,3)*D^coef_3(n,1)*T^coef_3(n,2));
    b=(obj.e^((-coef_3(n,4)*((D-coef_3(n,7))^2)-coef_3(n,5)*((T-coef_3(n,6))^2))));
    c=((coef_3(n,1)/D)-2*coef_3(n,4)*(D-coef_3(n,7)));
    d=(((coef_3(n,2)/T)-2*coef_3(n,5)*(T-coef_3(n,6)))^2-(coef_3(n,2)/(T^2))-2*coef_3(n,5));
    obj.fr_dtt=obj.fr_dtt+a*b*c*d;
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
    delta_dt=(1-D)*(0.64/0.3)*((D-1)^2)^(1/0.6-1);
    ex_t=-2*coef_4(n,6)*(T-1)*ex;
    ex_dt=(4*coef_4(n,5)*coef_4(n,6)*(D-1)*(T-1)*ex);
    ex_tt=(2*coef_4(n,6)*(T-1)^2-1)*2*coef_4(n,6)*ex;
    deltab_tt=2*coef_4(n,2)*delta^(coef_4(n,2)-1)+4*fi^2*coef_4(n,2)*(coef_4(n,2)-1)*delta^(coef_4(n,2)-2);
    ex_dtt=4*coef_4(n,5)*coef_4(n,6)*(D-1)*ex*(1-2*coef_4(n,6)*(T-1)^2);
    deltab_dtt=2*coef_4(n,2)*(coef_4(n,2)-1)*(2*fi*((coef_4(n,7)/coef_4(n,8))*(D-1)*((D-1)^2)^((1/(2*coef_4(n,8)))-1)*delta^(coef_4(n,2)-2)+fi*(coef_4(n,2)-2)*delta^(coef_4(n,2)-3)*delta_d)+delta^(coef_4(n,2)-2)*delta_d-fi*delta^(coef_4(n,2)-2)*delta_dt);



    
    p1=2*deltab_t*(ex_t+D*ex_dt);
    p2=D*(ex*deltab_dtt+2*ex_t*deltab_dt+deltab_d*ex_tt);%error here
    p3=deltab_tt*(ex+D*ex_d)+delta^coef_4(n,2)*(ex_tt+D*ex_dtt);
    p4=deltab_t*(ex_t+D*ex_dt);
    obj.fr_dtt=obj.fr_dtt+coef_4(n,4)*(p1+p2+p3+p4);
end
end

