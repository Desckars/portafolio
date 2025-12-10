package org.taller.moduloDeComercio.interfase.remota;

public class POSDTO {
    private int idPOS;
    private boolean habilitadoPOS;

    public POSDTO() {}

    public int getIdPOS() { 
        return idPOS; 
    }
    public void setIdPOS(int idPOS) { 
        this.idPOS = idPOS; 
    }

    public boolean isHabilitadoPOS() { 
        return habilitadoPOS; 
    }
    public void setHabilitadoPOS(boolean habilitadoPOS) { 
        this.habilitadoPOS = habilitadoPOS; 
    }
}
