function obj = Get_Fr_g( obj )
D=obj.Dg; T=obj.T;
obj.fr_g=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
coef_3=obj.coef_gauss;
coef_4=obj.coef_nonanalitic;
for n=1:obj.n_coef_pol;
    obj.fr_g=obj.fr_g+(coef_1(n,3)*(obj.Dg^coef_1(n,1))*(obj.T^coef_1(n,2)));
end
for n=1:obj.n_coef_exp;
     obj.fr_g=obj.fr_g+(coef_2(n,4)*(obj.Dg^coef_2(n,2))*(obj.T^coef_2(n,3))*(obj.e^(-(obj.Dg^coef_2(n,1)))));
end
for n=1:obj.n_coef_gauss;
    j=coef_3(n,4)*((D-coef_3(n,7))^2);
    k=coef_3(n,5)*((T-coef_3(n,6))^2);
    obj.fr_g=obj.fr_g+(coef_3(n,3)*(D^coef_3(n,1))*(T^coef_3(n,2))*(obj.e^(-(j+k))));
end
for n=1:obj.n_coef_nonanalitic;
    j=(1-T)+coef_4(n,7)*(((D-1)^2)^(1/(2*coef_4(n,8))));
    k=j^2+coef_4(n,3)*(((D-1)^2)^coef_4(n,1));
    l=obj.e^(-((coef_4(n,5)*((D-1)^2))+(coef_4(n,6)*((T-1)^2))));
    obj.fr_g=obj.fr_g+coef_4(n,4)*l*D*(k^coef_4(n,2));
end
end