function obj = Get_isentropic_t( obj )
T=obj.T;D=obj.D;
num=1+D*obj.fr_d-D*T*obj.fr_dt;
den=num^2-(T^2*(obj.fr_tt+obj.fi_tt)*(1+2*D*obj.fr_d+D^2*obj.fr_dd));
p11=-2*D*T*obj.fr_dtt*num;
p12=2*T*(obj.fr_tt+obj.fi_tt)*(1+2*D*obj.fr_d+D^2*obj.fr_dd);
p13=T^2*(obj.fr_ttt+obj.fi_ttt)*(1+2*D*obj.fr_d+D^2*obj.fr_dd);
p14=T^2*(obj.fr_tt+obj.fi_tt)*(2*D*obj.fr_dt+D^2*obj.fr_ddt);
p1=p11-(p12+p13+p14);
x=(-D*T*obj.fr_dtt*den-p1*num)/den^2;
x=x/(obj.R*obj.d);
obj.isentropic_t_p_coef_t=-x*T/obj.t;
end

