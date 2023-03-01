function obj = Get_third_v( obj )
syms D T;
obj.third_virial=0;x=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
for n=1:obj.n_coef_pol;
    x=x+(coef_1(n,3)*coef_1(n,1)*(coef_1(n,1)-1)*D^(coef_1(n,1)-2)*T^coef_1(n,2));
end
for n=1:obj.n_coef_exp;
    x=x+(coef_2(n,4)*D^(coef_2(n,2)-2)*T^coef_2(n,3)*obj.e^(-D^coef_2(n,1))*((coef_2(n,2)-coef_2(n,1)*D^coef_2(n,1))*(coef_2(n,2)-1-coef_2(n,1)*D^coef_2(n,1))-coef_2(n,1)^2*D^coef_2(n,1)));
end
obj.third_virial=subs(limit(x,'D',0),'T',obj.T)/(obj.dc^2);
end

