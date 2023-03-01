function obj = Get_w_t( obj )
D=obj.D; T=obj.T;
den=T^2*(obj.fi_tt+obj.fr_tt);
p1=((1+D*obj.fr_d-D*T*obj.fr_dt)^2/den-(1+2*D*obj.fr_d+D^2*obj.fr_dd))/T;
p2=2*D*obj.fr_dt+D^2*obj.fr_ddt;
p3=D*T*obj.fr_dtt*2*(1+D*obj.fr_d-D*T*obj.fr_dt)*den;
p4=(2*T*(obj.fi_tt+obj.fr_tt)+T^2*(obj.fi_ttt+obj.fr_ttt))*(1+D*obj.fr_d-D*T*obj.fr_dt)^2;
x=obj.R*obj.t*(p1+p2+(p3+p4)/den^2)/(2*obj.speed_sound);
obj.speed_sound_t=-x*T*1000/obj.t;
end

