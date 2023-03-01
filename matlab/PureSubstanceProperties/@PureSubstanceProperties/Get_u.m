function obj = Get_u( obj )
obj.internal_energy=(obj.T*(obj.fr_t+obj.fi_t))*obj.R*obj.t;
end

