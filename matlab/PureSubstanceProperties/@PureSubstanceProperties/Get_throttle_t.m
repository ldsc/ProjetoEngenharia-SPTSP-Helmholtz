function obj = Get_throttle_t( obj )
D=obj.D;T=obj.T;
num=(1+D*obj.fr_d-D*T*obj.fr_dt);
den=(1+2*D*obj.fr_d+(D^2)*obj.fr_dd);
x=(D*T*obj.fr_dtt*den+(2*D*obj.fr_dt+D^2*obj.fr_ddt)*num)/(den^2*obj.d);
obj.isot_throttle_coef_t=-x*T/obj.t;
end

