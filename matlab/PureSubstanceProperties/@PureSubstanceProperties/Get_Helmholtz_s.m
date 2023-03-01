function obj = Get_Helmholtz_s( obj )
            obj=obj.F_Ideal_tt;
            obj=obj.Get_Fr;
            obj=obj.Get_Fr_d;
            obj=obj.Get_Fr_g;
            obj=obj.Get_Fr_g_t;
            obj=obj.Get_Fr_t;
            obj=obj.Get_Fr_dd;
            obj=obj.Get_Fr_tt;
            obj=obj.Get_Fr_dt;     
end

