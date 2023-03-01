function obj = Get_Cp( obj )
x=-(obj.T^2)*(obj.fi_tt+obj.fr_tt);
x=x+((1+obj.D*obj.fr_d-obj.D*obj.T*obj.fr_dt)^2)/(1+2*obj.D*obj.fr_d+obj.fr_dd*(obj.D^2));
obj.isobaric_heat_C=x*obj.R;
obj=obj.Get_Cp_t;
obj=obj.Get_Cp_d;
end

