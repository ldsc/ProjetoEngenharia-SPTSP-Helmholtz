function obj = Get_throttle_d( obj )
D=obj.D;T=obj.T;
num=(1+D*obj.fr_d-D*T*obj.fr_dt);
den=(1+2*D*obj.fr_d+(D^2)*obj.fr_dd);
p1=-(1-num/den)/D;
p21=obj.fr_d+D*obj.fr_dd-T*obj.fr_dt-D*T*obj.fr_ddt;
p22=2*obj.fr_d+4*D*obj.fr_dd+D^2*obj.fr_ddd;
p2=-(p21*den-p22*num)/den^2;
x=(p1+p2)/obj.d;
obj.isot_throttle_coef_d=x/obj.dc;
end

