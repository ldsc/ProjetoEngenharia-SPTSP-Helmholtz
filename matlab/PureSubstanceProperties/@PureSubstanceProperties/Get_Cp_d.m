function obj = Get_Cp_d( obj )
T=obj.T; D=obj.D; fdd=obj.fr_dd; fd=obj.fr_d;
p1=-T^2*obj.fr_dtt;
den=1+2*D*fd+D^2*fdd;
p2=(fd+D*fdd-T*obj.fr_dt-D*T*obj.fr_ddt)*2*(1+D*fd-D*T*obj.fr_dt)*den;
p3=(2*fd+4*D*fdd+D^2*obj.fr_ddd)*(1+D*fd-D*T*obj.fr_dt)^2;
x=p1+(p2-p3)/den^2;
obj.isobaric_heat_C_d=x*obj.R/obj.dc;
end

