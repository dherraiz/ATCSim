/*
 * AirController.cpp
 *
 *  Created on: 21/07/2014
 *      Author: paco
 *
 *  Copyright 2014 Francisco Martín
 *
 *  This file is part of ATCSim.
 *
 *  ATCSim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AirController.h"
#include "Airport.h"
#include "Flight.h"
#include "Position.h"
#include <list>
#include <fstream>

namespace atcsim{

AirController::AirController() {
	// TODO Auto-generated constructor stub
  float vel_octo=200.0;
  float h_oct1=1000.0;
  float h_oct2=3000.0;

  //GENERAMOS LOS PUNTOS DE LOS 7 OCTOGONOS (RE)
  // PRIMER OCTOGONO

    Position pos_octo1_1(2606.0, 14780.0, h_oct1);
    Position pos_octo1_2(4069.0, 14457.0, h_oct1);
    Position pos_octo1_3(4867.0, 13187.0, h_oct1);
    Position pos_octo1_4(4533.0, 11724.0, h_oct1);
    Position pos_octo1_5(3263.0, 10926.0, h_oct1);
    Position pos_octo1_6(1801.0, 11260.0, h_oct1);
    Position pos_octo1_7(1002.0, 12530.0, h_oct1);
    Position pos_octo1_8(1336.0, 13993.0, h_oct1);


    rutas_octogonos_[1][1].pos=pos_octo1_1;
    rutas_octogonos_[1][2].pos=pos_octo1_2;
    rutas_octogonos_[1][3].pos=pos_octo1_3;
    rutas_octogonos_[1][4].pos=pos_octo1_4;
    rutas_octogonos_[1][5].pos=pos_octo1_5;
    rutas_octogonos_[1][6].pos=pos_octo1_6;
    rutas_octogonos_[1][7].pos=pos_octo1_7;
    rutas_octogonos_[1][8].pos=pos_octo1_8;
    for(int i=1;i<=8;i++){
      rutas_octogonos_[1][i].speed=vel_octo;
    }

    // SEGUNDO OCTOGONO

      Position pos_octo2_1(8767.0, 12194.0, h_oct1);
      Position pos_octo2_2(9940.0, 11259.0, h_oct1);
      Position pos_octo2_3(10108.0, 9768.0, h_oct1);
      Position pos_octo2_4(9172.0, 8596.0, h_oct1);
      Position pos_octo2_5(7682.0, 8428.0, h_oct1);
      Position pos_octo2_6(6509.0, 9363.0, h_oct1);
      Position pos_octo2_7(6341.0, 10854.0, h_oct1);
      Position pos_octo2_8(7277.0, 12026.0, h_oct1);


      rutas_octogonos_[2][1].pos=pos_octo2_1;
      rutas_octogonos_[2][2].pos=pos_octo2_2;
      rutas_octogonos_[2][3].pos=pos_octo2_3;
      rutas_octogonos_[2][4].pos=pos_octo2_4;
      rutas_octogonos_[2][5].pos=pos_octo2_5;
      rutas_octogonos_[2][6].pos=pos_octo2_6;
      rutas_octogonos_[2][7].pos=pos_octo2_7;
      rutas_octogonos_[2][8].pos=pos_octo2_8;
      for(int i=1;i<=8;i++){
        rutas_octogonos_[2][i].speed=vel_octo;
      }

    // TERCER OCTOGONO

      Position pos_octo3_1(13189.0, 7184.0, h_oct1);
      Position pos_octo3_2(13840.0, 5833.0, h_oct1);
      Position pos_octo3_3(13344.0, 4417.0, h_oct1);
      Position pos_octo3_4(11993.0, 3766.0, h_oct1);
      Position pos_octo3_5(10577.0, 4261.0, h_oct1);
      Position pos_octo3_6(9926.0, 5613.0, h_oct1);
      Position pos_octo3_7(10422.0, 7029.0, h_oct1);
      Position pos_octo3_8(11773.0, 7679.0, h_oct1);


      rutas_octogonos_[3][1].pos=pos_octo3_1;
      rutas_octogonos_[3][2].pos=pos_octo3_2;
      rutas_octogonos_[3][3].pos=pos_octo3_3;
      rutas_octogonos_[3][4].pos=pos_octo3_4;
      rutas_octogonos_[3][5].pos=pos_octo3_5;
      rutas_octogonos_[3][6].pos=pos_octo3_6;
      rutas_octogonos_[3][7].pos=pos_octo3_7;
      rutas_octogonos_[3][8].pos=pos_octo3_8;
      for(int i=1;i<=8;i++){
        rutas_octogonos_[3][i].speed=vel_octo;
      }

      // CUARTO OCTOGONO

      Position pos_octo4_1(15000.0, -748.0, h_oct1);
      Position pos_octo4_2(15000.0, 748.0, h_oct1);
      Position pos_octo4_3(13939.0, 1812.0, h_oct1);
      Position pos_octo4_4(12439.0, 1812.0, h_oct1);
      Position pos_octo4_5(11378.0, 748.0, h_oct1);
      Position pos_octo4_6(11378.0, -748.0, h_oct1);
      Position pos_octo4_7(12439.0, -1812.0, h_oct1);
      Position pos_octo4_8(13939.0, -1812.0, h_oct1);


      rutas_octogonos_[4][1].pos=pos_octo4_1;
      rutas_octogonos_[4][2].pos=pos_octo4_2;
      rutas_octogonos_[4][3].pos=pos_octo4_3;
      rutas_octogonos_[4][4].pos=pos_octo4_4;
      rutas_octogonos_[4][5].pos=pos_octo4_5;
      rutas_octogonos_[4][6].pos=pos_octo4_6;
      rutas_octogonos_[4][7].pos=pos_octo4_7;
      rutas_octogonos_[4][8].pos=pos_octo4_8;
      for(int i=1;i<=8;i++){
        rutas_octogonos_[4][i].speed=vel_octo;
      }

      // QUINTO OCTOGONO

        Position pos_octo5_1(13189.0, -7184.0, h_oct1);
        Position pos_octo5_2(13840.0, -5833.0, h_oct1);
        Position pos_octo5_3(13344.0, -4417.0, h_oct1);
        Position pos_octo5_4(11993.0, -3766.0, h_oct1);
        Position pos_octo5_5(10577.0, -4261.0, h_oct1);
        Position pos_octo5_6(9926.0, -5613.0, h_oct1);
        Position pos_octo5_7(10422.0, -7029.0, h_oct1);
        Position pos_octo5_8(11773.0, -7679.0, h_oct1);


        rutas_octogonos_[5][1].pos=pos_octo5_1;
        rutas_octogonos_[5][2].pos=pos_octo5_2;
        rutas_octogonos_[5][3].pos=pos_octo5_3;
        rutas_octogonos_[5][4].pos=pos_octo5_4;
        rutas_octogonos_[5][5].pos=pos_octo5_5;
        rutas_octogonos_[5][6].pos=pos_octo5_6;
        rutas_octogonos_[5][7].pos=pos_octo5_7;
        rutas_octogonos_[5][8].pos=pos_octo5_8;
        for(int i=1;i<=8;i++){
          rutas_octogonos_[5][i].speed=vel_octo;
        }

      // SEXTO OCTOGONO

        Position pos_octo6_1(8767.0, -12194.0, h_oct1);
        Position pos_octo6_2(9940.0, -11259.0, h_oct1);
        Position pos_octo6_3(10108.0, -9768.0, h_oct1);
        Position pos_octo6_4(9172.0, -8596.0, h_oct1);
        Position pos_octo6_5(7682.0, -8428.0, h_oct1);
        Position pos_octo6_6(6509.0, -9363.0, h_oct1);
        Position pos_octo6_7(6341.0, -10854.0, h_oct1);
        Position pos_octo6_8(7277.0, -12026.0, h_oct1);

        rutas_octogonos_[6][1].pos=pos_octo6_1;
        rutas_octogonos_[6][2].pos=pos_octo6_2;
        rutas_octogonos_[6][3].pos=pos_octo6_3;
        rutas_octogonos_[6][4].pos=pos_octo6_4;
        rutas_octogonos_[6][5].pos=pos_octo6_5;
        rutas_octogonos_[6][6].pos=pos_octo6_6;
        rutas_octogonos_[6][7].pos=pos_octo6_7;
        rutas_octogonos_[6][8].pos=pos_octo6_8;
        for(int i=1;i<=8;i++){
          rutas_octogonos_[6][i].speed=vel_octo;
        }

        // SÉPTIMO OCTOGONO

        Position pos_octo7_1(2606.0, -14780.0, h_oct1);
        Position pos_octo7_2(4069.0, -14457.0, h_oct1);
        Position pos_octo7_3(4867.0, -13187.0, h_oct1);
        Position pos_octo7_4(4533.0, -11724.0, h_oct1);
        Position pos_octo7_5(3263.0, -10926.0, h_oct1);
        Position pos_octo7_6(1801.0, -11260.0, h_oct1);
        Position pos_octo7_7(1002.0, -12530.0, h_oct1);
        Position pos_octo7_8(1336.0, -13993.0, h_oct1);


        rutas_octogonos_[7][1].pos=pos_octo7_1;
        rutas_octogonos_[7][2].pos=pos_octo7_2;
        rutas_octogonos_[7][3].pos=pos_octo7_3;
        rutas_octogonos_[7][4].pos=pos_octo7_4;
        rutas_octogonos_[7][5].pos=pos_octo7_5;
        rutas_octogonos_[7][6].pos=pos_octo7_6;
        rutas_octogonos_[7][7].pos=pos_octo7_7;
        rutas_octogonos_[7][8].pos=pos_octo7_8;
        for(int i=1;i<=8;i++){
          rutas_octogonos_[7][i].speed=vel_octo;
        }

        // 8 OCTOGONO

          Position pos_octo8_1(2606.0, 14780.0, h_oct2);
          Position pos_octo8_2(4069.0, 14457.0, h_oct2);
          Position pos_octo8_3(4867.0, 13187.0, h_oct2);
          Position pos_octo8_4(4533.0, 11724.0, h_oct2);
          Position pos_octo8_5(3263.0, 10926.0, h_oct2);
          Position pos_octo8_6(1801.0, 11260.0, h_oct2);
          Position pos_octo8_7(1002.0, 12530.0, h_oct2);
          Position pos_octo8_8(1336.0, 13993.0, h_oct2);


          rutas_octogonos_[8][1].pos=pos_octo8_1;
          rutas_octogonos_[8][2].pos=pos_octo8_2;
          rutas_octogonos_[8][3].pos=pos_octo8_3;
          rutas_octogonos_[8][4].pos=pos_octo8_4;
          rutas_octogonos_[8][5].pos=pos_octo8_5;
          rutas_octogonos_[8][6].pos=pos_octo8_6;
          rutas_octogonos_[8][7].pos=pos_octo8_7;
          rutas_octogonos_[8][8].pos=pos_octo8_8;
          for(int i=1;i<=8;i++){
            rutas_octogonos_[8][i].speed=vel_octo;
          }

          // 9 OCTOGONO

            Position pos_octo9_1(8767.0, 12194.0, h_oct2);
            Position pos_octo9_2(9940.0, 11259.0, h_oct2);
            Position pos_octo9_3(10108.0, 9768.0, h_oct2);
            Position pos_octo9_4(9172.0, 8596.0, h_oct2);
            Position pos_octo9_5(7682.0, 8428.0, h_oct2);
            Position pos_octo9_6(6509.0, 9363.0, h_oct2);
            Position pos_octo9_7(6341.0, 10854.0, h_oct2);
            Position pos_octo9_8(7277.0, 12026.0, h_oct2);


            rutas_octogonos_[9][1].pos=pos_octo9_1;
            rutas_octogonos_[9][2].pos=pos_octo9_2;
            rutas_octogonos_[9][3].pos=pos_octo9_3;
            rutas_octogonos_[9][4].pos=pos_octo9_4;
            rutas_octogonos_[9][5].pos=pos_octo9_5;
            rutas_octogonos_[9][6].pos=pos_octo9_6;
            rutas_octogonos_[9][7].pos=pos_octo9_7;
            rutas_octogonos_[9][8].pos=pos_octo9_8;
            for(int i=1;i<=8;i++){
              rutas_octogonos_[9][i].speed=vel_octo;
            }

          // 10 OCTOGONO

            Position pos_octo10_1(13189.0, 7184.0, h_oct2);
            Position pos_octo10_2(13840.0, 5833.0, h_oct2);
            Position pos_octo10_3(13344.0, 4417.0, h_oct2);
            Position pos_octo10_4(11993.0, 3766.0, h_oct2);
            Position pos_octo10_5(10577.0, 4261.0, h_oct2);
            Position pos_octo10_6(9926.0, 5613.0, h_oct2);
            Position pos_octo10_7(10422.0, 7029.0, h_oct2);
            Position pos_octo10_8(11773.0, 7679.0, h_oct2);


            rutas_octogonos_[10][1].pos=pos_octo10_1;
            rutas_octogonos_[10][2].pos=pos_octo10_2;
            rutas_octogonos_[10][3].pos=pos_octo10_3;
            rutas_octogonos_[10][4].pos=pos_octo10_4;
            rutas_octogonos_[10][5].pos=pos_octo10_5;
            rutas_octogonos_[10][6].pos=pos_octo10_6;
            rutas_octogonos_[10][7].pos=pos_octo10_7;
            rutas_octogonos_[10][8].pos=pos_octo10_8;
            for(int i=1;i<=8;i++){
              rutas_octogonos_[10][i].speed=vel_octo;
            }

            // 11 OCTOGONO

            Position pos_octo11_1(15000.0, -748.0, h_oct2);
            Position pos_octo11_2(15000.0, 748.0, h_oct2);
            Position pos_octo11_3(13939.0, 1812.0, h_oct2);
            Position pos_octo11_4(12439.0, 1812.0, h_oct2);
            Position pos_octo11_5(11378.0, 748.0, h_oct2);
            Position pos_octo11_6(11378.0, -748.0, h_oct2);
            Position pos_octo11_7(12439.0, -1812.0, h_oct2);
            Position pos_octo11_8(13939.0, -1812.0, h_oct2);


            rutas_octogonos_[11][1].pos=pos_octo11_1;
            rutas_octogonos_[11][2].pos=pos_octo11_2;
            rutas_octogonos_[11][3].pos=pos_octo11_3;
            rutas_octogonos_[11][4].pos=pos_octo11_4;
            rutas_octogonos_[11][5].pos=pos_octo11_5;
            rutas_octogonos_[11][6].pos=pos_octo11_6;
            rutas_octogonos_[11][7].pos=pos_octo11_7;
            rutas_octogonos_[11][8].pos=pos_octo11_8;
            for(int i=1;i<=8;i++){
              rutas_octogonos_[11][i].speed=vel_octo;
            }

            // 12 OCTOGONO

              Position pos_octo12_1(13189.0, -7184.0, h_oct2);
              Position pos_octo12_2(13840.0, -5833.0, h_oct2);
              Position pos_octo12_3(13344.0, -4417.0, h_oct2);
              Position pos_octo12_4(11993.0, -3766.0, h_oct2);
              Position pos_octo12_5(10577.0, -4261.0, h_oct2);
              Position pos_octo12_6(9926.0, -5613.0, h_oct2);
              Position pos_octo12_7(10422.0, -7029.0, h_oct2);
              Position pos_octo12_8(11773.0, -7679.0, h_oct2);


              rutas_octogonos_[12][1].pos=pos_octo12_1;
              rutas_octogonos_[12][2].pos=pos_octo12_2;
              rutas_octogonos_[12][3].pos=pos_octo12_3;
              rutas_octogonos_[12][4].pos=pos_octo12_4;
              rutas_octogonos_[12][5].pos=pos_octo12_5;
              rutas_octogonos_[12][6].pos=pos_octo12_6;
              rutas_octogonos_[12][7].pos=pos_octo12_7;
              rutas_octogonos_[12][8].pos=pos_octo12_8;
              for(int i=1;i<=8;i++){
                rutas_octogonos_[12][i].speed=vel_octo;
              }

            // 13 OCTOGONO

              Position pos_octo13_1(8767.0, -12194.0, h_oct2);
              Position pos_octo13_2(9940.0, -11259.0, h_oct2);
              Position pos_octo13_3(10108.0, -9768.0, h_oct2);
              Position pos_octo13_4(9172.0, -8596.0, h_oct2);
              Position pos_octo13_5(7682.0, -8428.0, h_oct2);
              Position pos_octo13_6(6509.0, -9363.0, h_oct2);
              Position pos_octo13_7(6341.0, -10854.0, h_oct2);
              Position pos_octo13_8(7277.0, -12026.0, h_oct2);

              rutas_octogonos_[13][1].pos=pos_octo13_1;
              rutas_octogonos_[13][2].pos=pos_octo13_2;
              rutas_octogonos_[13][3].pos=pos_octo13_3;
              rutas_octogonos_[13][4].pos=pos_octo13_4;
              rutas_octogonos_[13][5].pos=pos_octo13_5;
              rutas_octogonos_[13][6].pos=pos_octo13_6;
              rutas_octogonos_[13][7].pos=pos_octo13_7;
              rutas_octogonos_[13][8].pos=pos_octo13_8;
              for(int i=1;i<=8;i++){
                rutas_octogonos_[13][i].speed=vel_octo;
              }

              // 14 OCTOGONO

              Position pos_octo14_1(2606.0, -14780.0, h_oct2);
              Position pos_octo14_2(4069.0, -14457.0, h_oct2);
              Position pos_octo14_3(4867.0, -13187.0, h_oct2);
              Position pos_octo14_4(4533.0, -11724.0, h_oct2);
              Position pos_octo14_5(3263.0, -10926.0, h_oct2);
              Position pos_octo14_6(1801.0, -11260.0, h_oct2);
              Position pos_octo14_7(1002.0, -12530.0, h_oct2);
              Position pos_octo14_8(1336.0, -13993.0, h_oct2);


              rutas_octogonos_[0][1].pos=pos_octo14_1;
              rutas_octogonos_[0][2].pos=pos_octo14_2;
              rutas_octogonos_[0][3].pos=pos_octo14_3;
              rutas_octogonos_[0][4].pos=pos_octo14_4;
              rutas_octogonos_[0][5].pos=pos_octo14_5;
              rutas_octogonos_[0][6].pos=pos_octo14_6;
              rutas_octogonos_[0][7].pos=pos_octo14_7;
              rutas_octogonos_[0][8].pos=pos_octo14_8;
              for(int i=1;i<=8;i++){
                rutas_octogonos_[0][i].speed=vel_octo;
              }




    //GENERAMOS LOS PUNTOS DE LAS 7 RUTAS DE APROX.
    // PRIMERA RUTA
    Position pos_aprox1_1(5913.0, 4715.0, 100.0);
    Position pos_aprox1_2(6471.0, 3014.0, 100.0);
    Position pos_aprox1_3(6417.0, 2406.0, 100.0);
    Position pos_aprox1_4(6286.0, 1938.0, 100.0);
    Position pos_aprox1_5(6101.0, 1534.0, 100.0);
    Position pos_aprox1_6(5857.0, 1163.0, 100.0);
    Position pos_aprox1_7(5531.0, 802.0, 100.0);
    Position pos_aprox1_8(5041.0, 431.0, 100.0);

    rutas_aprox_[1][1].pos=pos_aprox1_1;
    rutas_aprox_[1][2].pos=pos_aprox1_2;
    rutas_aprox_[1][3].pos=pos_aprox1_3;
    rutas_aprox_[1][4].pos=pos_aprox1_4;
    rutas_aprox_[1][5].pos=pos_aprox1_5;
    rutas_aprox_[1][6].pos=pos_aprox1_6;
    rutas_aprox_[1][7].pos=pos_aprox1_7;
    rutas_aprox_[1][8].pos=pos_aprox1_8;



    for(int i=1;i<=8;i++){
      rutas_aprox_[1][i].speed=250;
    }

    // SEGUNDA RUTA
    Position pos_aprox2_1(7109.0, 4715.0, 100.0);
    Position pos_aprox2_2(6935.0, 3014.0, 100.0);
    Position pos_aprox2_3(6703.0, 2406.0, 100.0);
    Position pos_aprox2_4(6464.0, 1938.0, 100.0);
    Position pos_aprox2_5(6208.0, 1534.0, 100.0);
    Position pos_aprox2_6(5916.0, 1163.0, 100.0);
    Position pos_aprox2_7(5559.0, 802.0, 100.0);
    Position pos_aprox2_8(5056.0, 431.0, 100.0);

    rutas_aprox_[2][1].pos=pos_aprox2_1;
    rutas_aprox_[2][2].pos=pos_aprox2_2;
    rutas_aprox_[2][3].pos=pos_aprox2_3;
    rutas_aprox_[2][4].pos=pos_aprox2_4;
    rutas_aprox_[2][5].pos=pos_aprox2_5;
    rutas_aprox_[2][6].pos=pos_aprox2_6;
    rutas_aprox_[2][7].pos=pos_aprox2_7;
    rutas_aprox_[2][8].pos=pos_aprox2_8;

    for(int i=1;i<=8;i++){
      rutas_aprox_[2][i].speed=204;
    }

    // TERCERA RUTA
    Position pos_aprox3_1(9407.0, 4128.0, 1200.0);
    Position pos_aprox3_2(7962.0, 1858.0, 600.0);
    Position pos_aprox3_3(7139.0, 1160.0, 400.0);
    Position pos_aprox3_4(6217.0, 617.0, 200.0);
    Position pos_aprox3_5(5545.0, 342.0, 100.0);


    rutas_aprox_[3][1].pos=pos_aprox3_1;
    rutas_aprox_[3][2].pos=pos_aprox3_2;
    rutas_aprox_[3][3].pos=pos_aprox3_3;
    rutas_aprox_[3][4].pos=pos_aprox3_4;
    rutas_aprox_[3][5].pos=pos_aprox3_5;


    for(int i=1;i<=5;i++){
      rutas_aprox_[3][i].speed=164.5;
    }

    // CUARTA RUTA
    Position pos_aprox4_1(10546.0, -194.0, 1400.0);
    Position pos_aprox4_2(9754.0, 0.0, 1300.0);


    rutas_aprox_[4][1].pos=pos_aprox4_1;
    rutas_aprox_[4][2].pos=pos_aprox4_2;

    for(int i=1;i<=2;i++){
      rutas_aprox_[4][i].speed=144.125;
    }

    // QUINTA RUTA
    Position pos_aprox5_1(9407.0, -4128.0, 1200.0);
    Position pos_aprox5_2(7962.0, -1858.0, 600.0);
    Position pos_aprox5_3(7139.0, -1160.0, 400.0);
    Position pos_aprox5_4(6217.0, -617.0, 200.0);
    Position pos_aprox5_5(5545.0, -342.0, 100.0);


    rutas_aprox_[5][1].pos=pos_aprox5_1;
    rutas_aprox_[5][2].pos=pos_aprox5_2;
    rutas_aprox_[5][3].pos=pos_aprox5_3;
    rutas_aprox_[5][4].pos=pos_aprox5_4;
    rutas_aprox_[5][5].pos=pos_aprox5_5;


    for(int i=1;i<=5;i++){
      rutas_aprox_[5][i].speed=164.5;
    }

    // SEXTA RUTA
    Position pos_aprox6_1(7109.0, -4715.0, 100.0);
    Position pos_aprox6_2(6935.0, -3014.0, 100.0);
    Position pos_aprox6_3(6703.0, -2406.0, 100.0);
    Position pos_aprox6_4(6464.0, -1938.0, 100.0);
    Position pos_aprox6_5(6208.0, -1534.0, 100.0);
    Position pos_aprox6_6(5916.0, -1163.0, 100.0);
    Position pos_aprox6_7(5559.0, -802.0, 100.0);
    Position pos_aprox6_8(5056.0, -431.0, 100.0);

    rutas_aprox_[6][1].pos=pos_aprox6_1;
    rutas_aprox_[6][2].pos=pos_aprox6_2;
    rutas_aprox_[6][3].pos=pos_aprox6_3;
    rutas_aprox_[6][4].pos=pos_aprox6_4;
    rutas_aprox_[6][5].pos=pos_aprox6_5;
    rutas_aprox_[6][6].pos=pos_aprox6_6;
    rutas_aprox_[6][7].pos=pos_aprox6_7;
    //rutas_aprox_[6][8].pos=pos_aprox6_8;

    for(int i=1;i<=8;i++){
      rutas_aprox_[6][i].speed=204;
    }


    // SÉPTIMA RUTA
    Position pos_aprox7_1(5913.0, -4715.0, 100.0);
    Position pos_aprox7_2(6471.0, -3014.0, 100.0);
    Position pos_aprox7_3(6417.0, -2406.0, 100.0);
    Position pos_aprox7_4(6286.0, -1938.0, 100.0);
    Position pos_aprox7_5(6101.0, -1534.0, 100.0);
    Position pos_aprox7_6(5857.0, -1163.0, 100.0);
    Position pos_aprox7_7(5531.0, -802.0, 100.0);
    Position pos_aprox7_8(5041.0, -431.0, 100.0);

    rutas_aprox_[7][1].pos=pos_aprox7_1;
    rutas_aprox_[7][2].pos=pos_aprox7_2;
    rutas_aprox_[7][3].pos=pos_aprox7_3;
    rutas_aprox_[7][4].pos=pos_aprox7_4;
    rutas_aprox_[7][5].pos=pos_aprox7_5;
    rutas_aprox_[7][6].pos=pos_aprox7_6;
    rutas_aprox_[7][7].pos=pos_aprox7_7;
    rutas_aprox_[7][8].pos=pos_aprox7_8;

    for(int i=1;i<=8;i++){
      rutas_aprox_[7][i].speed=250;
    }

    // 8 RUTA(1)=2
    Position pos_aprox8_1(7109.0, 4715.0, 1200.0);
    Position pos_aprox8_2(6935.0, 3014.0, 660.0);
    Position pos_aprox8_3(6703.0, 2406.0, 470.0);
    Position pos_aprox8_4(6464.0, 1938.0, 470.0);
    Position pos_aprox8_5(6208.0, 1534.0, 470.0);
    Position pos_aprox8_6(5916.0, 1163.0, 470.0);
    Position pos_aprox8_7(5559.0, 802.0, 470.0);
    Position pos_aprox8_8(5056.0, 431.0, 470.0);

    rutas_aprox_[8][1].pos=pos_aprox8_1;
    rutas_aprox_[8][2].pos=pos_aprox8_2;
    rutas_aprox_[8][3].pos=pos_aprox8_3;
    rutas_aprox_[8][4].pos=pos_aprox8_4;
    rutas_aprox_[8][5].pos=pos_aprox8_5;
    rutas_aprox_[8][6].pos=pos_aprox8_6;
    rutas_aprox_[8][7].pos=pos_aprox8_7;
    rutas_aprox_[8][8].pos=pos_aprox8_8;



    for(int i=1;i<=8;i++){
      rutas_aprox_[8][i].speed=250;
    }

    // 9 RUTA(2)
    Position pos_aprox9_1(7109.0, 4715.0, 1200.0);
    Position pos_aprox9_2(6935.0, 3014.0, 660.0);
    Position pos_aprox9_3(6703.0, 2406.0, 470.0);
    Position pos_aprox9_4(6464.0, 1938.0, 470.0);
    Position pos_aprox9_5(6208.0, 1534.0, 470.0);
    Position pos_aprox9_6(5916.0, 1163.0, 470.0);
    Position pos_aprox9_7(5559.0, 802.0, 470.0);
    Position pos_aprox9_8(5056.0, 431.0, 470.0);

    rutas_aprox_[9][1].pos=pos_aprox9_1;
    rutas_aprox_[9][2].pos=pos_aprox9_2;
    rutas_aprox_[9][3].pos=pos_aprox9_3;
    rutas_aprox_[9][4].pos=pos_aprox9_4;
    rutas_aprox_[9][5].pos=pos_aprox9_5;
    rutas_aprox_[9][6].pos=pos_aprox9_6;
    rutas_aprox_[9][7].pos=pos_aprox9_7;
    rutas_aprox_[9][8].pos=pos_aprox9_8;

    for(int i=1;i<=8;i++){
      rutas_aprox_[9][i].speed=204;
    }

    // 10 RUTA(3)
    Position pos_aprox10_1(9407.0, 4128.0, 2428.0);
    Position pos_aprox10_2(7962.0, 1858.0, 1449.0);
    Position pos_aprox10_3(7139.0, 1160.0, 1057.0);
    Position pos_aprox10_4(6217.0, 617.0, 668.0);
    Position pos_aprox10_5(5545.0, 342.0, 406.0);


    rutas_aprox_[10][1].pos=pos_aprox10_1;
    rutas_aprox_[10][2].pos=pos_aprox10_2;
    rutas_aprox_[10][3].pos=pos_aprox10_3;
    rutas_aprox_[10][4].pos=pos_aprox10_4;
    rutas_aprox_[10][5].pos=pos_aprox10_5;


    for(int i=1;i<=5;i++){
      rutas_aprox_[10][i].speed=164.5;
    }

    // 11 RUTA  (4)
    Position pos_aprox11_1(10430.0, 2757.0, 1677.0);
    Position pos_aprox11_2(8500.0, 4500.0, 731.0);
    Position pos_aprox11_3(6472.0, 3976.0, 100.0);
    Position pos_aprox11_4(5666.0, 2611.0, 100.0);
    Position pos_aprox11_5(5530.0, 802.0, 100.0);
    Position pos_aprox11_6(5056.0, 350.0, 100.0);



    rutas_aprox_[11][1].pos=pos_aprox11_1;
    rutas_aprox_[11][2].pos=pos_aprox11_2;
    rutas_aprox_[11][3].pos=pos_aprox11_3;
    rutas_aprox_[11][4].pos=pos_aprox11_4;
    rutas_aprox_[11][5].pos=pos_aprox11_5;
    rutas_aprox_[11][6].pos=pos_aprox11_6;

    for(int i=1;i<=6;i++){
      rutas_aprox_[11][i].speed=144.125;
    }

    // 12 RUTA(5)
    Position pos_aprox12_1(9407.0, -4128.0, 2428.0);
    Position pos_aprox12_2(7962.0, -1858.0, 1449.0);
    Position pos_aprox12_3(7139.0, -1160.0, 1057.0);
    Position pos_aprox12_4(6217.0, -617.0, 668.0);
    Position pos_aprox12_5(5545.0, -342.0, 406.0);

    rutas_aprox_[12][1].pos=pos_aprox12_1;
    rutas_aprox_[12][2].pos=pos_aprox12_2;
    rutas_aprox_[12][3].pos=pos_aprox12_3;
    rutas_aprox_[12][4].pos=pos_aprox12_4;
    rutas_aprox_[12][5].pos=pos_aprox12_5;


    for(int i=1;i<=5;i++){
      rutas_aprox_[12][i].speed=164.5;
    }

    // 13 RUTA(6)
    Position pos_aprox13_1(7109.0, -4715.0, 1200.0);
    Position pos_aprox13_2(6935.0, -3014.0, 660.0);
    Position pos_aprox13_3(6703.0, -2406.0, 470.0);
    Position pos_aprox13_4(6464.0, -1938.0, 470.0);
    Position pos_aprox13_5(6208.0, -1534.0, 470.0);
    Position pos_aprox13_6(5916.0, -1163.0, 470.0);
    Position pos_aprox13_7(5559.0, -802.0, 470.0);
    Position pos_aprox13_8(5056.0, -431.0, 470.0);

    rutas_aprox_[13][1].pos=pos_aprox13_1;
    rutas_aprox_[13][2].pos=pos_aprox13_2;
    rutas_aprox_[13][3].pos=pos_aprox13_3;
    rutas_aprox_[13][4].pos=pos_aprox13_4;
    rutas_aprox_[13][5].pos=pos_aprox13_5;
    rutas_aprox_[13][6].pos=pos_aprox13_6;
    rutas_aprox_[13][7].pos=pos_aprox13_7;

    for(int i=1;i<=8;i++){
      rutas_aprox_[13][i].speed=204;
    }


    // 14 RUTA(7)=13
    Position pos_aprox14_1(7109.0, -4715.0, 1200.0);
    Position pos_aprox14_2(6935.0, -3014.0, 660.0);
    Position pos_aprox14_3(6703.0, -2406.0, 470.0);
    Position pos_aprox14_4(6464.0, -1938.0, 470.0);
    Position pos_aprox14_5(6208.0, -1534.0, 470.0);
    Position pos_aprox14_6(5916.0, -1163.0, 470.0);
    Position pos_aprox14_7(5559.0, -802.0, 470.0);
    Position pos_aprox14_8(5056.0, -431.0, 470.0);

    rutas_aprox_[0][1].pos=pos_aprox14_1;
    rutas_aprox_[0][2].pos=pos_aprox14_2;
    rutas_aprox_[0][3].pos=pos_aprox14_3;
    rutas_aprox_[0][4].pos=pos_aprox14_4;
    rutas_aprox_[0][5].pos=pos_aprox14_5;
    rutas_aprox_[0][6].pos=pos_aprox14_6;
    rutas_aprox_[0][7].pos=pos_aprox14_7;
    rutas_aprox_[0][8].pos=pos_aprox14_8;

    for(int i=1;i<=8;i++){
      rutas_aprox_[0][i].speed=250;
    }

}

AirController::~AirController() {
	// TODO Auto-generated destructor stub
}

void
AirController::doWork()
{
  std::list<Flight*> flights = Airport::getInstance()->getFlights();
  std::list<Flight*>::iterator it;

//----------------------TIEMPO---------------------------------------------------------
  float acum;
  float acum_total;
  int periodos;
  float segundos;
  std::string id;
  float start_time;

  acum=Airport::getInstance()->getAcum();
  periodos=Airport::getInstance()->getPeriodos();
  acum_total=acum+periodos*INC_DIFF;
  segundos=acum_total/1000000.0;

//-------------------------------------------------------------------------------
  int paso=Airport::getInstance()->getPaso();
  float tiempo_ultimo=Airport::getInstance()->getTiempoUltimo();



  Position pos01_0(3500.0, 0.0, 100.0);
  Position pos01_1(1500.0, 0.0, 50.0);
  Position pos01_2(100.0, 0.0, 25.0);
  Position pos01_3(75.0, 0.0, 25.0);
  Position pos01_4(-750.0, 0.0, 25.0);

  Route r01_0, r01_1, r01_2, r01_3, r01_4;

  r01_0.pos = pos01_0;
  r01_0.speed = 500.0;
  r01_1.pos = pos01_1;
  r01_1.speed = 500.0;
  r01_2.pos = pos01_2;
  r01_2.speed = 150.0;
  r01_3.pos = pos01_3;
  r01_3.speed = 19.0;
  r01_4.pos = pos01_4;
  r01_4.speed = 15.0;

  //ALETERNADOR
  if((paso==0) && ((segundos-tiempo_ultimo)>=30)){
    Airport::getInstance()->setPaso(1);
    Airport::getInstance()->setTiempoUltimo(segundos);
  }

//  std::cout<<"DIFERENCIA: "<<segundos-tiempo_ultimo<<", paso="<<paso<<'\n'<<'\n';

  for(it = flights.begin(); it!=flights.end(); ++it)
  {
    //CAMBIO A RUTA DE APROXIMACIÓN

    //CAMBIO DE LA PRIMERA RUTA
    if((((*it)->getFirstBearing())<=toRadians(-90))&&(((*it)->getFirstBearing())>=toRadians(-90-24)) /*&& alternador==1*/ && paso==1)
    {
      int rev_fase=((*it)->get_fase());
      Position pos=(*it)->getPosition();
      float x=pos.get_x();
      float y=pos.get_y();



      if ((x>1600)&&(x<2000)&&(y>11060)&&(y<11460)){
        (*it)->set_fase(2);
      }

      if(((*it)->get_fase())!=rev_fase){
        Airport::getInstance()->setPaso(0);
        (*it)-> getRoute()->clear();
      }
    }

    //CAMBIO DE LA SEGUNDA RUTA
    if((((*it)->getFirstBearing())<=toRadians(-90-25.717))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*2)) /*&& alternador==5*/ && paso==1)
    {
      int rev_fase=((*it)->get_fase());
      Position pos=(*it)->getPosition();
      float x=pos.get_x();
      float y=pos.get_y();



      if ((x>6309)&&(x<6709)&&(y>9163)&&(y<9563)){
        (*it)->set_fase(2);
      }

      if(((*it)->get_fase())!=rev_fase){
         (*it)-> getRoute()->clear();
         Airport::getInstance()->setPaso(0);
      }
    }

    //CAMBIO DE LA TERCERA RUTA
    if((((*it)->getFirstBearing())<=toRadians(-90-25.717*2))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*3)) /*&& alternador==3*/ && paso==1)
    {
      int rev_fase=((*it)->get_fase());
      Position pos=(*it)->getPosition();
      float x=pos.get_x();
      float y=pos.get_y();



      if ((x>9726)&&(x<10126)&&(y>5412)&&(y<5812)){
        (*it)->set_fase(2);
      }

      if(((*it)->get_fase())!=rev_fase){
         (*it)-> getRoute()->clear();
         Airport::getInstance()->setPaso(0);
      }
    }

    //CAMBIO DE LA CUARTA RUTA
    if(((((*it)->getFirstBearing())<=toRadians(-180+12.856))||(((*it)->getFirstBearing())>=toRadians(180-12.856)) )/*&& alternador==7*/ && paso==1)
    {
      int rev_fase=((*it)->get_fase());
      Position pos=(*it)->getPosition();
      float x=pos.get_x();
      float y=pos.get_y();



      if ((y<-551)&&(y>-951)&&(x>11179)&&(x<11579)){
        (*it)->set_fase(2);
      }

      if(((*it)->get_fase())!=rev_fase){
         (*it)-> getRoute()->clear();
         Airport::getInstance()->setPaso(0);
      }
    }

    //CAMBIO DE LA QUINTA RUTA
    if((((*it)->getFirstBearing())>=toRadians(90+25.717*2))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*3)) /*&& alternador==4*/ && paso==1)
    {
      int rev_fase=((*it)->get_fase());
      Position pos=(*it)->getPosition();
      float x=pos.get_x();
      float y=pos.get_y();


      if ((x>9726)&&(x<10126)&&(y<-5412)&&(y>-5812)){
        (*it)->set_fase(2);
      }

      if(((*it)->get_fase())!=rev_fase){
         (*it)-> getRoute()->clear();
         Airport::getInstance()->setPaso(0);
      }
    }

    //CAMBIO DE LA SEXTA RUTA
    if((((*it)->getFirstBearing())>=toRadians(90+25.717))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*2)) /*&& alternador==2*/ && paso==1)
    {
      int rev_fase=((*it)->get_fase());
      Position pos=(*it)->getPosition();
      float x=pos.get_x();
      float y=pos.get_y();


      if ((x>6309)&&(x<6709)&&(y<-9163)&&(y>-9563)){
        (*it)->set_fase(2);
      }

      if(((*it)->get_fase())!=rev_fase){
         (*it)-> getRoute()->clear();
         Airport::getInstance()->setPaso(0);
      }
    }

    //CAMBIO DE LA SÉPTIMA RUTA
    if((((*it)->getFirstBearing())>=toRadians(90))&&(((*it)->getFirstBearing())<=toRadians(90+25.7)) && /*alternador==6 && */ paso==1)
    {
      int rev_fase=((*it)->get_fase());
      Position pos=(*it)->getPosition();
      float x=pos.get_x();
      float y=pos.get_y();

      if ((x>1600)&&(x<2000)&&(y<-11060)&&(y>-11460)){
        (*it)->set_fase(2);
      }

      if(((*it)->get_fase())!=rev_fase){
         (*it)-> getRoute()->clear();
         Airport::getInstance()->setPaso(0);
         Airport::getInstance()->setTiempoUltimo(segundos);
      }
    }


    Position pos=(*it)->getPosition();
    float z=pos.get_z();


    if(((*it)->getRoute()->empty())&&(((*it)->get_fase())==1))
    {



      //PRIMERA RUTA DE ESPERA
      if ((((*it)->getFirstBearing())<=toRadians(-90))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7)) && (z<=3000))
      {

        int re=1;
        std::cout <<"RUTA DE ESPERA "<<re<<'\n';
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_oct(re,1);
        r02=get_ruta_oct(re,2);
        r03=get_ruta_oct(re,3);
        r04=get_ruta_oct(re,4);
        r05=get_ruta_oct(re,5);
        r06=get_ruta_oct(re,6);
        r07=get_ruta_oct(re,7);
        r08=get_ruta_oct(re,8);

        if ((((*it)->getFirstBearing())<=toRadians(-90))&&(((*it)->getFirstBearing())>=toRadians(-90-24))){

          (*it)->getRoute()->push_back(r01);
          (*it)->getRoute()->push_front(r02);
          (*it)->getRoute()->push_front(r03);
          (*it)->getRoute()->push_front(r04);
          (*it)->getRoute()->push_front(r05);
          (*it)->getRoute()->push_front(r06);
          (*it)->getRoute()->push_front(r07);
          (*it)->getRoute()->push_front(r08);


        }else{
          (*it)->getRoute()->push_back(r02);
          (*it)->getRoute()->push_front(r03);
          (*it)->getRoute()->push_front(r04);
          (*it)->getRoute()->push_front(r05);
          (*it)->getRoute()->push_front(r06);
          (*it)->getRoute()->push_front(r07);
          (*it)->getRoute()->push_front(r08);
          (*it)->getRoute()->push_front(r01);
        }
      }
        //SEGUNDA RUTA DE ESPERA
      if ((((*it)->getFirstBearing())<=toRadians(-90-25.717))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*2)) && (z<=3000))
      {

        int re=2;
        std::cout <<"RUTA DE ESPERA "<<re<<'\n';
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_oct(re,1);
        r02=get_ruta_oct(re,2);
        r03=get_ruta_oct(re,3);
        r04=get_ruta_oct(re,4);
        r05=get_ruta_oct(re,5);
        r06=get_ruta_oct(re,6);
        r07=get_ruta_oct(re,7);
        r08=get_ruta_oct(re,8);

        if ((((*it)->getFirstBearing())<=toRadians(-90-25.717))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7-24))){

          (*it)->getRoute()->push_back(r01);
          (*it)->getRoute()->push_front(r02);
          (*it)->getRoute()->push_front(r03);
          (*it)->getRoute()->push_front(r04);
          (*it)->getRoute()->push_front(r05);
          (*it)->getRoute()->push_front(r06);
          (*it)->getRoute()->push_front(r07);
          (*it)->getRoute()->push_front(r08);


        }else{
          (*it)->getRoute()->push_back(r02);
          (*it)->getRoute()->push_front(r03);
          (*it)->getRoute()->push_front(r04);
          (*it)->getRoute()->push_front(r05);
          (*it)->getRoute()->push_front(r06);
          (*it)->getRoute()->push_front(r07);
          (*it)->getRoute()->push_front(r08);
          (*it)->getRoute()->push_front(r01);
        }
      }

      //TERCERA RUTA DE ESPERA
    if ((((*it)->getFirstBearing())<=toRadians(-90-25.717*2))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*3)) && (z<=3000))
    {

      int re=3;
      std::cout <<"RUTA DE ESPERA "<<re<<'\n';
      Route r01, r02, r03, r04, r05, r06, r07, r08;
      r01=get_ruta_oct(re,1);
      r02=get_ruta_oct(re,2);
      r03=get_ruta_oct(re,3);
      r04=get_ruta_oct(re,4);
      r05=get_ruta_oct(re,5);
      r06=get_ruta_oct(re,6);
      r07=get_ruta_oct(re,7);
      r08=get_ruta_oct(re,8);

      if ((((*it)->getFirstBearing())<=toRadians(-90-25.717*2))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*2-24))){

        (*it)->getRoute()->push_back(r01);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r08);


      }else{
        (*it)->getRoute()->push_back(r02);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r01);
      }
    }

    //CUARTA RUTA DE ESPERA
    if (((((*it)->getFirstBearing())<=toRadians(-180+12.856))||(((*it)->getFirstBearing())>=toRadians(180-12.856))) && (z<=3000))
    {

      int re=4;
      std::cout <<"RUTA DE ESPERA "<<re<<'\n';
      Route r01, r02, r03, r04, r05, r06, r07, r08;
      r01=get_ruta_oct(re,1);
      r02=get_ruta_oct(re,2);
      r03=get_ruta_oct(re,3);
      r04=get_ruta_oct(re,4);
      r05=get_ruta_oct(re,5);
      r06=get_ruta_oct(re,6);
      r07=get_ruta_oct(re,7);
      r08=get_ruta_oct(re,8);

      if((((*it)->getFirstBearing())<=toRadians(-180+11.155))||(((*it)->getFirstBearing())>=toRadians(180-12.856))){

        (*it)->getRoute()->push_back(r01);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r08);


      }else{
        (*it)->getRoute()->push_back(r02);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r01);
      }
    }
      //QUINTA RUTA DE ESPERA
    if ((((*it)->getFirstBearing())>=toRadians(90+25.717*2))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*3)) && (z<=3000))
    {

      int re=5;
      std::cout <<"RUTA DE ESPERA "<<re<<'\n';
      Route r01, r02, r03, r04, r05, r06, r07, r08;
      r01=get_ruta_oct(re,1);
      r02=get_ruta_oct(re,2);
      r03=get_ruta_oct(re,3);
      r04=get_ruta_oct(re,4);
      r05=get_ruta_oct(re,5);
      r06=get_ruta_oct(re,6);
      r07=get_ruta_oct(re,7);
      r08=get_ruta_oct(re,8);

      if ((((*it)->getFirstBearing())>=toRadians(90+25.717*2))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*2+24))){

        (*it)->getRoute()->push_back(r01);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r08);


      }else{
        (*it)->getRoute()->push_back(r02);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r01);
      }
    }

    //SEXTA RUTA DE ESPERA
  if ((((*it)->getFirstBearing())>=toRadians(90+25.717))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*2)) && (z<=3000))
  {

    int re=6;
    std::cout <<"RUTA DE ESPERA "<<re<<'\n';
    Route r01, r02, r03, r04, r05, r06, r07, r08;
    r01=get_ruta_oct(re,1);
    r02=get_ruta_oct(re,2);
    r03=get_ruta_oct(re,3);
    r04=get_ruta_oct(re,4);
    r05=get_ruta_oct(re,5);
    r06=get_ruta_oct(re,6);
    r07=get_ruta_oct(re,7);
    r08=get_ruta_oct(re,8);

    if ((((*it)->getFirstBearing())>=toRadians(90+25.717))&&(((*it)->getFirstBearing())<=toRadians(90+25.7+24))){

      (*it)->getRoute()->push_back(r01);
      (*it)->getRoute()->push_front(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);


    }else{
      (*it)->getRoute()->push_back(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);
      (*it)->getRoute()->push_front(r01);
    }
  }

  //SÉPTIMA RUTA DE ESPERA
  if ((((*it)->getFirstBearing())>=toRadians(90))&&(((*it)->getFirstBearing())<=toRadians(90+25.7)) && (z<=3000))
  {
    int re=7;
    std::cout <<"RUTA DE ESPERA "<<re<<'\n';
    Route r01, r02, r03, r04, r05, r06, r07, r08;
    r01=get_ruta_oct(re,1);
    r02=get_ruta_oct(re,2);
    r03=get_ruta_oct(re,3);
    r04=get_ruta_oct(re,4);
    r05=get_ruta_oct(re,5);
    r06=get_ruta_oct(re,6);
    r07=get_ruta_oct(re,7);
    r08=get_ruta_oct(re,8);

    if ((((*it)->getFirstBearing())>=toRadians(90))&&(((*it)->getFirstBearing())<=toRadians(90+24))){
      (*it)->getRoute()->push_back(r01);
      (*it)->getRoute()->push_front(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);


    }else{
      (*it)->getRoute()->push_back(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);
      (*it)->getRoute()->push_front(r01);
    }
  }

  //8 RUTA DE ESPERA
  if ((((*it)->getFirstBearing())<=toRadians(-90))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7)) && (z>3000))
  {

    int re=8;
    std::cout <<"RUTA DE ESPERA "<<re<<'\n';
    Route r01, r02, r03, r04, r05, r06, r07, r08;
    r01=get_ruta_oct(re,1);
    r02=get_ruta_oct(re,2);
    r03=get_ruta_oct(re,3);
    r04=get_ruta_oct(re,4);
    r05=get_ruta_oct(re,5);
    r06=get_ruta_oct(re,6);
    r07=get_ruta_oct(re,7);
    r08=get_ruta_oct(re,8);

    if ((((*it)->getFirstBearing())<=toRadians(-90))&&(((*it)->getFirstBearing())>=toRadians(-90-24))){

      (*it)->getRoute()->push_back(r01);
      (*it)->getRoute()->push_front(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);


    }else{
      (*it)->getRoute()->push_back(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);
      (*it)->getRoute()->push_front(r01);
    }
  }
    //9 RUTA DE ESPERA
  if ((((*it)->getFirstBearing())<=toRadians(-90-25.717))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*2)) && (z>3000))
  {

    int re=9;
    std::cout <<"RUTA DE ESPERA "<<re<<'\n';
    Route r01, r02, r03, r04, r05, r06, r07, r08;
    r01=get_ruta_oct(re,1);
    r02=get_ruta_oct(re,2);
    r03=get_ruta_oct(re,3);
    r04=get_ruta_oct(re,4);
    r05=get_ruta_oct(re,5);
    r06=get_ruta_oct(re,6);
    r07=get_ruta_oct(re,7);
    r08=get_ruta_oct(re,8);

    if ((((*it)->getFirstBearing())<=toRadians(-90-25.717))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7-24))){

      (*it)->getRoute()->push_back(r01);
      (*it)->getRoute()->push_front(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);


    }else{
      (*it)->getRoute()->push_back(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);
      (*it)->getRoute()->push_front(r01);
    }
  }

  //10 RUTA DE ESPERA
if ((((*it)->getFirstBearing())<=toRadians(-90-25.717*2))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*3)) && (z>3000))
{

  int re=10;
  std::cout <<"RUTA DE ESPERA "<<re<<'\n';
  Route r01, r02, r03, r04, r05, r06, r07, r08;
  r01=get_ruta_oct(re,1);
  r02=get_ruta_oct(re,2);
  r03=get_ruta_oct(re,3);
  r04=get_ruta_oct(re,4);
  r05=get_ruta_oct(re,5);
  r06=get_ruta_oct(re,6);
  r07=get_ruta_oct(re,7);
  r08=get_ruta_oct(re,8);

  if ((((*it)->getFirstBearing())<=toRadians(-90-25.717*2))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*2-24))){

    (*it)->getRoute()->push_back(r01);
    (*it)->getRoute()->push_front(r02);
    (*it)->getRoute()->push_front(r03);
    (*it)->getRoute()->push_front(r04);
    (*it)->getRoute()->push_front(r05);
    (*it)->getRoute()->push_front(r06);
    (*it)->getRoute()->push_front(r07);
    (*it)->getRoute()->push_front(r08);


  }else{
    (*it)->getRoute()->push_back(r02);
    (*it)->getRoute()->push_front(r03);
    (*it)->getRoute()->push_front(r04);
    (*it)->getRoute()->push_front(r05);
    (*it)->getRoute()->push_front(r06);
    (*it)->getRoute()->push_front(r07);
    (*it)->getRoute()->push_front(r08);
    (*it)->getRoute()->push_front(r01);
  }
}

//11 RUTA DE ESPERA
  if (((((*it)->getFirstBearing())<=toRadians(-180+12.856))||(((*it)->getFirstBearing())>=toRadians(180-12.856))) && (z>3000))
  {

    int re=11;
    std::cout <<"RUTA DE ESPERA "<<re<<'\n';
    Route r01, r02, r03, r04, r05, r06, r07, r08;
    r01=get_ruta_oct(re,1);
    r02=get_ruta_oct(re,2);
    r03=get_ruta_oct(re,3);
    r04=get_ruta_oct(re,4);
    r05=get_ruta_oct(re,5);
    r06=get_ruta_oct(re,6);
    r07=get_ruta_oct(re,7);
    r08=get_ruta_oct(re,8);

    if((((*it)->getFirstBearing())<=toRadians(-180+11.155))||(((*it)->getFirstBearing())>=toRadians(180-12.856))){

      (*it)->getRoute()->push_back(r01);
      (*it)->getRoute()->push_front(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);


    }else{
      (*it)->getRoute()->push_back(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);
      (*it)->getRoute()->push_front(r01);
    }
  }
  //12 RUTA DE ESPERA
  if ((((*it)->getFirstBearing())>=toRadians(90+25.717*2))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*3)) && (z>3000))
  {

    int re=12;
    std::cout <<"RUTA DE ESPERA "<<re<<'\n';
    Route r01, r02, r03, r04, r05, r06, r07, r08;
    r01=get_ruta_oct(re,1);
    r02=get_ruta_oct(re,2);
    r03=get_ruta_oct(re,3);
    r04=get_ruta_oct(re,4);
    r05=get_ruta_oct(re,5);
    r06=get_ruta_oct(re,6);
    r07=get_ruta_oct(re,7);
    r08=get_ruta_oct(re,8);

    if ((((*it)->getFirstBearing())>=toRadians(90+25.717*2))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*2+24))){

      (*it)->getRoute()->push_back(r01);
      (*it)->getRoute()->push_front(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);


    }else{
      (*it)->getRoute()->push_back(r02);
      (*it)->getRoute()->push_front(r03);
      (*it)->getRoute()->push_front(r04);
      (*it)->getRoute()->push_front(r05);
      (*it)->getRoute()->push_front(r06);
      (*it)->getRoute()->push_front(r07);
      (*it)->getRoute()->push_front(r08);
      (*it)->getRoute()->push_front(r01);
    }
  }

      //13 RUTA DE ESPERA
      if ((((*it)->getFirstBearing())>=toRadians(90+25.717))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*2)) && (z>3000))
      {

        int re=13;
        std::cout <<"RUTA DE ESPERA "<<re<<'\n';
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_oct(re,1);
        r02=get_ruta_oct(re,2);
        r03=get_ruta_oct(re,3);
        r04=get_ruta_oct(re,4);
        r05=get_ruta_oct(re,5);
        r06=get_ruta_oct(re,6);
        r07=get_ruta_oct(re,7);
        r08=get_ruta_oct(re,8);

        if ((((*it)->getFirstBearing())>=toRadians(90+25.717))&&(((*it)->getFirstBearing())<=toRadians(90+25.7+24))){

          (*it)->getRoute()->push_back(r01);
          (*it)->getRoute()->push_front(r02);
          (*it)->getRoute()->push_front(r03);
          (*it)->getRoute()->push_front(r04);
          (*it)->getRoute()->push_front(r05);
          (*it)->getRoute()->push_front(r06);
          (*it)->getRoute()->push_front(r07);
          (*it)->getRoute()->push_front(r08);


        }else{
          (*it)->getRoute()->push_back(r02);
          (*it)->getRoute()->push_front(r03);
          (*it)->getRoute()->push_front(r04);
          (*it)->getRoute()->push_front(r05);
          (*it)->getRoute()->push_front(r06);
          (*it)->getRoute()->push_front(r07);
          (*it)->getRoute()->push_front(r08);
          (*it)->getRoute()->push_front(r01);
        }
      }

//14 RUTA DE ESPERA
    if ((((*it)->getFirstBearing())>=toRadians(90))&&(((*it)->getFirstBearing())<=toRadians(90+25.7)) && (z>3000))
    {
      int re=0;
      std::cout <<"RUTA DE ESPERA "<<re<<'\n';
      Route r01, r02, r03, r04, r05, r06, r07, r08;
      r01=get_ruta_oct(re,1);
      r02=get_ruta_oct(re,2);
      r03=get_ruta_oct(re,3);
      r04=get_ruta_oct(re,4);
      r05=get_ruta_oct(re,5);
      r06=get_ruta_oct(re,6);
      r07=get_ruta_oct(re,7);
      r08=get_ruta_oct(re,8);

      if ((((*it)->getFirstBearing())>=toRadians(90))&&(((*it)->getFirstBearing())<=toRadians(90+24))){
        (*it)->getRoute()->push_back(r01);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r08);


      }else{
        (*it)->getRoute()->push_back(r02);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r01);
    }
    }

}
//CAMBIO A RUTA DE APROXIMACIÓN/
    if(((*it)->getRoute()->empty()) && (((*it)->get_fase())==2))
    {



      (*it)->getRoute()->push_back(r01_4);
      (*it)->getRoute()->push_front(r01_3);
      (*it)->getRoute()->push_front(r01_2);
      (*it)->getRoute()->push_front(r01_1);
      (*it)->getRoute()->push_front(r01_0);

      //PRIMERA RE
      if ((((*it)->getFirstBearing())<=toRadians(-90))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7)) && (z<=2000))
      {
        int re=1;
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);
        r06=get_ruta_aprox(re,6);
        r07=get_ruta_aprox(re,7);
        r08=get_ruta_aprox(re,8);

        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);

      }

      //SEGUNDA RE
      if ((((*it)->getFirstBearing())<=toRadians(-90-25.717))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*2)) && (z<=2000))
      {
        int re=2;
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);
        r06=get_ruta_aprox(re,6);
        r07=get_ruta_aprox(re,7);
        r08=get_ruta_aprox(re,8);

        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);

      }

      //TERCERA RE
      if ((((*it)->getFirstBearing())<=toRadians(-90-25.717*2))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*3)) && (z<=2000))
      {
        int re=3;
        Route r01, r02, r03, r04, r05;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);


        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);
      }

      //CUARTA RE
      if ((((*it)->getFirstBearing())<=toRadians(-180+12.856))||(((*it)->getFirstBearing())>=toRadians(180-12.856)) && (z<=2000))
      {
        int re=4;
        Route r01, r02;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);


        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);
      }

      //QUINTA RE
      if ((((*it)->getFirstBearing())>=toRadians(90+25.717*2))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*3)) && (z<=2000))
      {
        int re=5;
        Route r01, r02, r03, r04, r05;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);


        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);
      }

      //SEXTA RE
      if ((((*it)->getFirstBearing())>=toRadians(90+25.717))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*2)) && (z<=2000))
      {
        int re=6;
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);
        r06=get_ruta_aprox(re,6);
        r07=get_ruta_aprox(re,7);
        //r08=get_ruta_aprox(re,8);

        //(*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);

      }

      //SÉPTIMA RE
      if ((((*it)->getFirstBearing())>=toRadians(90))&&(((*it)->getFirstBearing())<=toRadians(90+25.7)) && (z<=2000))
      {
        int re=7;
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);
        r06=get_ruta_aprox(re,6);
        r07=get_ruta_aprox(re,7);
        r08=get_ruta_aprox(re,8);

        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);

      }

      //8 RE
      if ((((*it)->getFirstBearing())<=toRadians(-90))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7)) && (z>2000))
      {
        int re=8;
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);
        r06=get_ruta_aprox(re,6);
        r07=get_ruta_aprox(re,7);
        r08=get_ruta_aprox(re,8);

        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);

      }

      //9 RE
      if ((((*it)->getFirstBearing())<=toRadians(-90-25.717))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*2)) && (z>2000))
      {
        int re=9;
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);
        r06=get_ruta_aprox(re,6);
        r07=get_ruta_aprox(re,7);
        r08=get_ruta_aprox(re,8);

        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);

      }

      //10 RE
      if ((((*it)->getFirstBearing())<=toRadians(-90-25.717*2))&&(((*it)->getFirstBearing())>=toRadians(-90-25.7*3)) && (z>2000))
      {
        int re=10;
        Route r01, r02, r03, r04, r05;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);


        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);
      }

      //11 RE
      if ((((*it)->getFirstBearing())<=toRadians(-180+12.856))||(((*it)->getFirstBearing())>=toRadians(180-12.856)) && (z>2000))
      {
        int re=11;
        Route r01, r02;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);


        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);
      }

      //12 RE
      if ((((*it)->getFirstBearing())>=toRadians(90+25.717*2))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*3)) && (z>2000))
      {
        int re=12;
        Route r01, r02, r03, r04, r05;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);


        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);
      }

      //13 RE
      if ((((*it)->getFirstBearing())>=toRadians(90+25.717))&&(((*it)->getFirstBearing())<=toRadians(90+25.7*2)) && (z>2000))
      {
        int re=13;
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);
        r06=get_ruta_aprox(re,6);
        r07=get_ruta_aprox(re,7);
        //r08=get_ruta_aprox(re,8);

        //(*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);

      }

      //14 RE
      if ((((*it)->getFirstBearing())>=toRadians(90))&&(((*it)->getFirstBearing())<=toRadians(90+25.7)) && (z>2000))
      {
        int re=0;
        Route r01, r02, r03, r04, r05, r06, r07, r08;
        r01=get_ruta_aprox(re,1);
        r02=get_ruta_aprox(re,2);
        r03=get_ruta_aprox(re,3);
        r04=get_ruta_aprox(re,4);
        r05=get_ruta_aprox(re,5);
        r06=get_ruta_aprox(re,6);
        r07=get_ruta_aprox(re,7);
        r08=get_ruta_aprox(re,8);

        (*it)->getRoute()->push_front(r08);
        (*it)->getRoute()->push_front(r07);
        (*it)->getRoute()->push_front(r06);
        (*it)->getRoute()->push_front(r05);
        (*it)->getRoute()->push_front(r04);
        (*it)->getRoute()->push_front(r03);
        (*it)->getRoute()->push_front(r02);
        (*it)->getRoute()->push_front(r01);

      }


  }
}

}

};  // namespace atcsim
