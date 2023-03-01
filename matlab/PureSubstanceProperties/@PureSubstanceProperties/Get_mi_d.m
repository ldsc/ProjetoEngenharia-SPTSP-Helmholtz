function obj = Get_mi_d(obj)
T=obj.T;D=obj.D;fdd=obj.fr_dd;
den=(1+D*obj.fr_d-D*T*obj.fr_dt)^2;
den=den-(T^2*(obj.fr_tt+obj.fi_tt)*(1+2*D*obj.fr_d+D^2*obj.fr_dd));
num=D*obj.fr_d+D^2*obj.fr_dd+D*T*obj.fr_dt;
p1=num/(den*D);
p2=obj.fr_d+3*D*fdd+D^2*fdd+T*obj.fr_dt+D*T*obj.fr_ddt;
p31=(obj.fr_d+D*fdd-T*obj.fr_dt-D*T*obj.fr_ddt)*2*(1+D*obj.fr_d-D*T*obj.fr_dt);
p32=T^2*obj.fr_dtt*(1+2*D*obj.fr_d+D^2*obj.fr_dd);
p33=T^2*(obj.fr_tt+obj.fi_tt)*(2*obj.fr_d+4*D*fdd+D^2*fdd);
p3=p31-p32-p33;
x=p1-(p2*den-p3*num)/den^2;
x=x/(obj.R*obj.d);
obj.Joule_Thomson_coef_d=x*1000/obj.dc;
end

