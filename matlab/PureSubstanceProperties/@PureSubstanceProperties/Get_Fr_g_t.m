function obj = Get_Fr_g_t( obj )

D=obj.Dg; T=obj.T;
obj.fr_g_t=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
coef_3=obj.coef_gauss;
coef_4=obj.coef_nonanalitic;
for n=1:obj.n_coef_pol;
    obj.fr_g_t=obj.fr_g_t+(coef_1(n,3)*coef_1(n,2)*D^coef_1(n,1)*T^(coef_1(n,2)-1));
end
for n=1:obj.n_coef_exp;
    obj.fr_g_t=obj.fr_g_t+(coef_2(n,4)*coef_2(n,3)*D^coef_2(n,2)*T^(coef_2(n,3)-1)*obj.e^(-D^coef_2(n,1)));
end
for n=1:obj.n_coef_gauss;
    a=(coef_3(n,3)*D^coef_3(n,1)*T^coef_3(n,2));
    b=(obj.e^((-coef_3(n,4)*((D-coef_3(n,7))^2)-coef_3(n,5)*((T-coef_3(n,6))^2))));
    c=((coef_3(n,2)/T)-2*coef_3(n,5)*(T-coef_3(n,6)));
    obj.fr_g_t=obj.fr_g_t+a*b*c;
end
for n=1:obj.n_coef_nonanalitic;
    fi=(1-T)+coef_4(n,7)*(((D-1)^2)^(1/(2*coef_4(n,8))));
    delta=fi^2+coef_4(n,3)*(((D-1)^2)^coef_4(n,1));
    ex=obj.e^(-((coef_4(n,5)*((D-1)^2))+(coef_4(n,6)*((T-1)^2))));
    deltab_t=-2*fi*coef_4(n,2)*(delta^(coef_4(n,2)-1));
    ex_t=-2*coef_4(n,6)*(T-1)*ex;

    
    obj.fr_g_t=obj.fr_g_t+coef_4(n,4)*D*((delta^coef_4(n,2))*ex_t+deltab_t*ex);
end
end

