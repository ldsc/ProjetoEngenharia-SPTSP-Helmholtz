function obj = Get_Cs( obj )
x=-(obj.T^2)*(obj.fi_tt+obj.fr_tt);
y=(1+obj.D*obj.fr_d-obj.D*obj.T*obj.fr_dt)/(1+2*obj.D*obj.fr_d+obj.fr_dd*(obj.D^2));
y=y*((1+obj.D*obj.fr_d-obj.D*obj.T*obj.fr_dt)-obj.dc*obj.pressure_t/(obj.R*obj.D));
obj.saturated_liq_heat_C=(x+y)*obj.R;
end

