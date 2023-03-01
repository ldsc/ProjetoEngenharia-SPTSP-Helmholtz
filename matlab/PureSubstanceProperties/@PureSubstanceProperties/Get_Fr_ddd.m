function obj = Get_Fr_ddd( obj )
D=obj.D; T=obj.T;
obj.fr_ddd=0;
coef_1=obj.coef_pol;      
coef_2=obj.coef_exp;
coef_3=obj.coef_gauss;
coef_4=obj.coef_nonanalitic;

for n=1:obj.n_coef_pol;
    obj.fr_ddd=obj.fr_ddd+coef_1(n,3)*coef_1(n,1)*(coef_1(n,1)-1)*(coef_1(n,1)-2)*D^(coef_1(n,1)-3)*T^coef_1(n,2);
end
for n=1:obj.n_coef_exp;
    Dc=D^coef_2(n,1);
    c=coef_2(n,1);
    obj.fr_ddd=obj.fr_ddd+coef_2(n,4)*obj.e^(-Dc)*T^coef_2(n,3)*(D^(coef_2(n,2)-3)*((coef_2(n,2)-c*Dc)*(coef_2(n,2)-1-c*Dc)-c^2*Dc)*(coef_2(n,2)-2)-c*D^(c-1)*D^(coef_2(n,2)-2)*((coef_2(n,2)-c*Dc)*(coef_2(n,2)-1-c*Dc)-c^2*Dc)-D^(coef_2(n,2)-2)*c^2*(c*D^(c-1)+D^(c-1)*(2*coef_2(n,2)-1-2*c*Dc)));
end
for n=1:obj.n_coef_gauss; 
    a=(coef_3(n,3)*T^coef_3(n,2));
    b=(obj.e^(-coef_3(n,4)*(D-coef_3(n,7))^2-coef_3(n,5)*((T-coef_3(n,6))^2)));
    c=-2*coef_3(n,4)*D^coef_3(n,1)+4*(coef_3(n,4)^2)*D^coef_3(n,1)*(D-coef_3(n,7))^2-4*coef_3(n,1)*coef_3(n,4)*D^(coef_3(n,1)-1)*(D-coef_3(n,7))+coef_3(n,1)*(coef_3(n,1)-1)*D^(coef_3(n,1)-2);
    d=-2*coef_3(n,4)*coef_3(n,1)*D^(coef_3(n,1)-1)+4*(coef_3(n,4)^2)*coef_3(n,1)*D^(coef_3(n,1)-1)*(D-coef_3(n,7))^2+8*(coef_3(n,4)^2)*D^coef_3(n,1)*(D-coef_3(n,7))-4*coef_3(n,1)*(coef_3(n,1)-1)*coef_3(n,4)*D^(coef_3(n,1)-2)*(D-coef_3(n,7))-4*coef_3(n,1)*coef_3(n,4)*D^(coef_3(n,1)-1)+coef_3(n,1)*(coef_3(n,1)-1)*(coef_3(n,1)-2)*D^(coef_3(n,1)-3);
    obj.fr_ddd=obj.fr_ddd-2*coef_3(n,4)*(D-coef_3(n,7))*a*b*c;
    obj.fr_ddd=obj.fr_ddd+a*b*d;
end
for n=1:obj.n_coef_nonanalitic;
    b=coef_4(n,2);
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
    delta_ddd=delta_dd/(D-1)-delta_d/(D-1)^2;
     
    delta_ddd=delta_ddd+2*(D-1)*(4*coef_4(n,3)*coef_4(n,1)*(coef_4(n,1)-1)*((D-1)^2)^(coef_4(n,1)-2)+2*(coef_4(n,7)/coef_4(n,8))^2*(((D-1)^2)^(1/(2*coef_4(n,8))-1))^2+(4*coef_4(n,7)/coef_4(n,8))*fi*(1/(2*coef_4(n,8))-1)*((D-1)^2)^(1/(2*coef_4(n,8))-2));
    delta_ddd=delta_ddd+(D-1)^3*(8*coef_4(n,3)*coef_4(n,1)*(coef_4(n,1)-1)*(coef_4(n,1)-2)*((D-1)^2)^(coef_4(n,1)-3)+12*(coef_4(n,7)/coef_4(n,8))^2*(1/(2*coef_4(n,8))-1)*((D-1)^2)^(1/(2*coef_4(n,8))-1)*((D-1)^2)^(1/(2*coef_4(n,8))-2)+8*(coef_4(n,7)/coef_4(n,8))*fi*(1/(2*coef_4(n,8))-1)*(1/(2*coef_4(n,8))-2)*((D-1)^2)^(1/(2*coef_4(n,8))-3));
    ex_ddd=4*coef_4(n,5)^2*(D-1)*(3-2*coef_4(n,5)*(D-1)^2)*ex;
    deltab_ddd=b*(delta^(b-1)*delta_ddd+(b-1)*delta^(b-2)*delta_d*delta_dd+(b-1)*(b-2)*delta^(b-3)*delta_d^3+(b-1)*delta^(b-2)*delta_dd*2*delta_d);



    
    p1=3*deltab_d*(2*ex_d+D*ex_dd);
    p2=3*deltab_dd*(ex+D*ex_d);
    p3=delta^coef_4(n,2)*(3*ex_dd+D*ex_ddd);
    p4=deltab_ddd*D*ex;
    obj.fr_ddd=obj.fr_ddd+coef_4(n,4)*(p1+p2+p3+p4);

    
end
end

