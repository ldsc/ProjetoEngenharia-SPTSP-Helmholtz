function obj = Get_mi_t(obj)
T=obj.T;D=obj.D;fdt=obj.fr_dt;
den=(1+D*obj.fr_d-D*T*obj.fr_dt)^2;
den=den-(T^2*(obj.fr_tt+obj.fi_tt)*(1+2*D*obj.fr_d+D^2*obj.fr_dd));
num=D*obj.fr_d+D^2*obj.fr_dd+D*T*obj.fr_dt;
p1=2*D*fdt+D^2*obj.fr_ddt+D*T*obj.fr_dtt;
p21=-2*T*(obj.fr_tt+obj.fi_tt)*(1+2*D*obj.fr_d+D^2*obj.fr_dd);
p22=-T^2*(obj.fr_ttt+obj.fi_ttt)*(1+2*D*obj.fr_d+D^2*obj.fr_dd);
p23=-T^2*(obj.fr_tt+obj.fi_tt)*(2*D*fdt+D^2*obj.fr_ddt);
p2=-2*D*T*obj.fr_dtt*(1+D*obj.fr_d-D*T*fdt)+(p21+p22+p23);
x=-(p1*den-p2*num)/den^2;
x=x/(obj.R*obj.d);
obj.Joule_Thomson_coef_t=-x*T*1000/obj.t;
end

