function obj = Get_Gibbs_d( obj )
obj.Gibbs_energy_d=obj.R*obj.t*(obj.fi_d+2*obj.fr_d+obj.D*obj.fr_dd)/obj.dc;
end
