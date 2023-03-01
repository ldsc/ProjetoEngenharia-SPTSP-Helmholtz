function obj = Get_enthalpy_d( obj )
obj.enthalpy_d=obj.tc*obj.R*(obj.fr_dt+(obj.fr_d+obj.D*obj.fr_dd)/obj.T)/obj.dc;
end

