 function obj = Get_Fr_ttt( obj )
D=obj.D; T=obj.T;
obj.fr_ttt=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
coef_3=obj.coef_gauss;
coef_4=obj.coef_nonanalitic;
for n=1:obj.n_coef_pol;
    obj.fr_ttt=obj.fr_ttt+(coef_1(n,3)*coef_1(n,2)*(coef_1(n,2)-1)*(coef_1(n,2)-2)*D^coef_1(n,1)*T^(coef_1(n,2)-3));
end
for n=1:obj.n_coef_exp;
    obj.fr_ttt=obj.fr_ttt+(coef_2(n,4)*coef_2(n,3)*(coef_2(n,3)-1)*(coef_2(n,3)-2)*D^coef_2(n,2)*T^(coef_2(n,3)-3)*obj.e^(-D^coef_2(n,1)));
end
for n=1:obj.n_coef_gauss;
    a=(coef_3(n,3)*D^coef_3(n,1)*T^coef_3(n,2));
    b=(obj.e^((-coef_3(n,4)*((D-coef_3(n,7))^2)-coef_3(n,5)*((T-coef_3(n,6))^2))));
    c=(coef_3(n,2)/obj.T^3+(coef_3(n,2)/obj.T-2*coef_3(n,5)*(obj.T-coef_3(n,6)))*((coef_3(n,2)/obj.T-2*coef_3(n,5)*(obj.T-coef_3(n,6)))^2-3*(coef_3(n,2)/obj.T^2+2*coef_3(n,5))));
    obj.fr_ttt=obj.fr_ttt+a*b*c;
end
for n=1:obj.n_coef_nonanalitic;
    fi=(1-T)+coef_4(n,7)*(((D-1)^2)^(1/(2*coef_4(n,8))));
    delta=fi^2+coef_4(n,3)*(((D-1)^2)^coef_4(n,1));
    ex=obj.e^(-((coef_4(n,5)*((D-1)^2))+(coef_4(n,6)*((T-1)^2))));
    deltab_t=-2*fi*coef_4(n,2)*(delta^(coef_4(n,2)-1));
    ex_t=-2*coef_4(n,6)*(T-1)*ex;
    ex_tt=(2*coef_4(n,6)*(T-1)^2-1)*2*coef_4(n,6)*ex;
    deltab_tt=2*coef_4(n,2)*delta^(coef_4(n,2)-1)+4*fi^2*coef_4(n,2)*(coef_4(n,2)-1)*delta^(coef_4(n,2)-2);   
    deltab_ttt=-12*coef_4(n,2)*(coef_4(n,2)-1)*fi*delta^(coef_4(n,2)-2)-8*coef_4(n,2)*(coef_4(n,2)-1)*(coef_4(n,2)-2)*fi^3*delta^(coef_4(n,2)-3);
    ex_ttt=2*coef_4(n,6)*ex_t*(2*coef_4(n,6)*(obj.T-1)^2-1)+8*coef_4(n,6)^2*(obj.T-1)*ex;
    
    obj.fr_ttt=obj.fr_ttt+coef_4(n,4)*D*(deltab_ttt*ex+3*deltab_tt*ex_t+3*deltab_t*ex_tt+delta^coef_4(n,2)*ex_ttt);
end
end

