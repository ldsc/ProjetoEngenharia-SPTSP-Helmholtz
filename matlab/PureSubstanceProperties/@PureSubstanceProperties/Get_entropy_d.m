function obj = Get_entropy_d( obj )
obj.entropy_d=obj.R*(obj.T*obj.fr_dt-obj.fr_d-obj.fi_d)/obj.dc;
end

