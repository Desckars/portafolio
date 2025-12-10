package org.taller.moduloDeCompra.aplicacion;

import java.util.List;

import org.taller.moduloDeCompra.dominio.DataCompra;

public interface ModuloCompras {

    public void procesarPago(DataCompra datosCompra);
    public List<DataCompra> resumenVentasDiarias(String comercioId);
    public List<DataCompra> resumenVentasPorPeriodo(String idComercio,String fechaIni,String fechaEnd); // ejemplo de formato para fecha 01-05-2025 o 01/05/2025 
    public float montoActualVendido(String comercioId);
} 
