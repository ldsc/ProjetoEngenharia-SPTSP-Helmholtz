function obj = Get_Cv( obj )
obj.isochoric_heat_C=(-(obj.T^2)*(obj.fr_tt+obj.fi_tt))*obj.R;
end

