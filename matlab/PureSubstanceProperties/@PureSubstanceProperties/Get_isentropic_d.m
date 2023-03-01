function obj = Get_isentropic_d( obj )
T=obj.T;D=obj.D;
num=1+D*obj.fr_d-D*T*obj.fr_dt;
den=num^2-(T^2*(obj.fr_tt+obj.fi_tt)*(1+2*D*obj.fr_d+D^2*obj.fr_dd));

p1=obj.fr_d+D*obj.fr_dd-T*obj.fr_dt-D*T*obj.fr_dtt;
p21=2*p1*num;
p22=T^2*obj.fr_dtt*(1+2*D*obj.fr_d+D^2*obj.fr_dd);
p23=T^2*(obj.fr_tt+obj.fi_tt)*(4*D*obj.fr_dd+2*obj.fr_d+D^2*obj.fr_ddd);
p2=p21-(p22+p23);
Jd=(p1*den-p2*num)/den^2;
x=Jd-num/(den*D);
x=x/(obj.R*obj.d);
obj.isentropic_t_p_coef_d=x/obj.dc;
end

