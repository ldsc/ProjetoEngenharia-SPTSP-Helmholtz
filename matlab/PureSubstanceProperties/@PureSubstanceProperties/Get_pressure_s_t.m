function obj = Get_pressure_s_t( obj )
fator=obj.dg*obj.d*obj.R/(obj.dg-obj.d);
obj.pressure_t=fator*(log(obj.dg/obj.d)+obj.fr_g-obj.fr-obj.T*(obj.fr_g_t-obj.fr_t))/100;
end