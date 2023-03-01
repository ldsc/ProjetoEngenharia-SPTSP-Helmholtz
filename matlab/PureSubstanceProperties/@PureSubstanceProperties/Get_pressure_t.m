function obj = Get_pressure_t( obj )
obj.pressure_t=obj.d*obj.R*obj.t*(obj.D*obj.fr_dt-((obj.D*obj.fr_d+1)/obj.T))/100;
obj.pressure_t=-obj.pressure_t*obj.T/obj.t;
end

