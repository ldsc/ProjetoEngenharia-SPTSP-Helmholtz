function obj = Get_entropy( obj )
obj.entropy=(obj.T*(obj.fi_t+obj.fr_t)-(obj.fi+obj.fr))*obj.R;
end

