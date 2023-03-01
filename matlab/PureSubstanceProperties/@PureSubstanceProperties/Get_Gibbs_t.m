function obj = Get_Gibbs_t( obj )
obj.Gibbs_energy_t=obj.tc*(obj.fi_t+obj.fr_t+obj.D*obj.fr_dt);
obj.Gibbs_energy_t=obj.Gibbs_energy_t-obj.t*(1+obj.fi+obj.fr+obj.D*obj.fr_d);
obj.Gibbs_energy_t=-obj.Gibbs_energy_t*obj.R/obj.t;
end
