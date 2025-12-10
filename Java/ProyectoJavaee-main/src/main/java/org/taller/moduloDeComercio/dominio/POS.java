package org.taller.moduloDeComercio.dominio;
import jakarta.persistence.*;
import jakarta.xml.bind.annotation.XmlTransient;


    @Entity
    @Table(name = "POS")
    public class POS {

        @Id
        @GeneratedValue(strategy = GenerationType.IDENTITY)
        private int idPOS;


        @ManyToOne
        @JoinColumn(name = "Comercio_id")
        private Comercio comercio;

        private boolean habilitadoPOS;
        public POS() {
            // Constructor por defecto requerido por JPA
        }
        public POS( Comercio comercio) {
            this.comercio=comercio;
            this.habilitadoPOS = false;
        }

        public int getIdPOS() {
            return idPOS;
        }
        @XmlTransient
        public Comercio getComercio(){
            return comercio;
        }

        public boolean getHabilitadoPOS(){
            return habilitadoPOS;
        }

        public void setIdPOS(int id) {
            this.idPOS = id;
        }

        public void setComercio(Comercio comercio){
            this.comercio=comercio;
        }
        
        public void setHabilitadoPOS(boolean habilitado){
            this.habilitadoPOS = habilitado;
        }

}
