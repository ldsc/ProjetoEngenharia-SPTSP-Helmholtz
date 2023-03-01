function obj = Get_w_d( obj )
D=obj.D; T=obj.T; fd=obj.fr_d; fdd=obj.fr_dd;
den=T^2*(obj.fi_tt+obj.fr_tt);
p1=2*obj.fr_d+4*D*obj.fr_dd+D^2*obj.fr_ddd;
p2=(fd+D*fdd-T*obj.fr_dt-D*T*obj.fr_ddt)*2*(1+D*fd-D*T*obj.fr_dt)*den;
p3=T^2*obj.fr_dtt*(1+D*fd-D*T*obj.fr_dt)^2;
x=obj.R*obj.t*(p1-(p2-p3)/den^2)/(2*obj.speed_sound);
obj.speed_sound_d=x*1000/obj.dc;
end

