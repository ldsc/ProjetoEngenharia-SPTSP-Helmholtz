function obj = Get_Gibbs( obj )
obj.Gibbs_energy=(1+obj.fi+obj.fr+(obj.D*obj.fr_d))*obj.R*obj.t;
end
