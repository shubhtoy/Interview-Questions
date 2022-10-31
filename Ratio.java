package com.geektrust.backend;

public class Ratio {

    Integer CorporationWaterRatio;
    Integer BorewellWaterRatio;

    public Ratio(Integer CorporationWaterRatio,Integer BorewellWaterRatio)
    {
        this.CorporationWaterRatio = CorporationWaterRatio;
        this.BorewellWaterRatio = BorewellWaterRatio;
    }
    
    public Integer getCorporationRatio()
    {
        return CorporationWaterRatio;
    }
    public Integer getBorewellWaterRatio()
    {
        return BorewellWaterRatio;
    }
    public double getCorporationFraction()
    {
        return getCorporationRatio()/(double)(getCorporationRatio()+getBorewellWaterRatio());
    }
    public double getBorewellFraction()
    {
        return getBorewellWaterRatio()/(double)(getCorporationRatio()+getBorewellWaterRatio());
    }

}