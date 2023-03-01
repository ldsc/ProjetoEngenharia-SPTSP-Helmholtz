function obj = Get_Cp_t( obj )
T=obj.T; D=obj.D;
den=1+2*D*obj.fr_d+D^2*obj.fr_dd;
p1=-2*D*T*obj.fr_dtt*(1+D*obj.fr_d-D*T*obj.fr_dt)*den;
p2=(2*D*obj.fr_dt+D^2*obj.fr_ddt)*(1+D*obj.fr_d-D*T*obj.fr_dt)^2;
f=(p1-p2)/(den^2);
obj.isobaric_heat_C_t=obj.R*f;
obj.isobaric_heat_C_t=obj.isochoric_heat_C_t-obj.isobaric_heat_C_t*T/obj.t;
end

