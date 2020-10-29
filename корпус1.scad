$fn=256;
cube( size = [120,50,1] );
translate([0,-7.46,15]) rotate([60, 0, 0]) difference() {
        cube( size = [120,50,1] );
        translate([25,13.5,0]) cube( size = [70,23,1] );
}
translate([0,58.66,15]) rotate([120, 0, 0]) cube( size = [120,50,1] );
translate([0, 0, 10]) rotate([0,90,0]) difference() {
        cylinder(h = 120, r = 10);
        cylinder(h = 120, r = 9);
        translate([-0.866*5.78,-10.36 +0.5*5.78 ,120]) rotate([0, 90, 60]) cube( size = [120,120,1] );
        translate([-10, 0, 0]) cube( size=[20, 10, 120]);
        translate([0, -3, 0]) rotate([0,0,120]) cube( size=[20, 10, 120]);
}
translate([120, 50, 10]) rotate([180,90,0]) difference() {       
        cylinder(h = 120, r = 10);
        cylinder(h = 120, r = 9);
        translate([-0.866*5.78,-10.36 +0.5*5.78 ,120]) rotate([0, 90, 60]) cube( size = [120,120,1] );
        translate([-10, 0, 0]) cube( size=[20, 10, 120]);
        translate([0, -3, 0]) rotate([0,0,120]) cube( size=[20, 10, 120]);
}
translate([0, -33.8, 53.4]) rotate([-65,0,0]) translate([120, 25, 53.3]) rotate([0,-90,0]) difference() {       
        cylinder(h = 120, r = 10);
        cylinder(h = 120, r = 9);
        translate([-0.866*5.78,-10.36 +0.5*5.78 ,120]) rotate([0, 90, 60]) cube( size = [120,120,1] );
        translate([-10, 0, 0]) cube( size=[20, 10, 120]);
        translate([0, -3, 0]) rotate([0,0,120]) cube( size=[20, 10, 120]);
}
translate([0, 0, 10]) rotate([0,90,0]) cylinder(h = 1, r = 10);
translate([0, 50, 10]) rotate([0,90,0]) cylinder(h = 1, r = 10);
translate([-119, -33.8, 53.4]) rotate([-65,0,0]) translate([120, 25, 53.3]) rotate([0,-90,0]) cylinder(h = 1, r = 10);
polyhedron(points = [ 
                        [0, -8.66, 15], 
                        [0, 0, 0], 
                        [0, 50, 0], 
                        [0, 58.66, 15], 
                        [0, 33.66, 58.3],
                        [0, 17.34, 58.3],
                        
                        
                        
                        [1, -8.66, 15], 
                        [1, 0, 0], 
                        [1, 50, 0], 
                        [1, 58.66, 15], 
                        [1, 33.66, 58.3],
                        [1, 17.34, 58.3]
                     ], 
            faces = [ 
                        [0, 1, 2, 3, 4, 5],
                        
                        [0, 6, 7, 1],
                        [1, 7, 8, 2],
                        [2, 8, 9, 3],
                        [3, 9, 10, 4],
                        [4, 10, 11, 5],
                        [5, 11, 6, 0],
                        
                        [11, 10, 9, 8, 7, 6]
                       
                    ]
);
translate([119, 0, 10]) rotate([0,90,0]) cylinder(h = 1, r = 10);
translate([119, 50, 10]) rotate([0,90,0]) cylinder(h = 1, r = 10);
translate([0, -33.8, 53.4]) rotate([-65,0,0]) translate([120, 25, 53.3]) rotate([0,-90,0]) cylinder(h = 1, r = 10);
translate([119, 0, 0]) polyhedron(points = [ 
                        [0, -8.66, 15], 
                        [0, 0, 0], 
                        [0, 50, 0], 
                        [0, 58.66, 15], 
                        [0, 33.66, 58.3],
                        [0, 17.34, 58.3],
                        
                        
                        
                        [1, -8.66, 15], 
                        [1, 0, 0], 
                        [1, 50, 0], 
                        [1, 58.66, 15], 
                        [1, 33.66, 58.3],
                        [1, 17.34, 58.3]
                     ], 
            faces = [ 
                        [0, 1, 2, 3, 4, 5],
                        
                        [0, 6, 7, 1],
                        [1, 7, 8, 2],
                        [2, 8, 9, 3],
                        [3, 9, 10, 4],
                        [4, 10, 11, 5],
                        [5, 11, 6, 0],
                        
                        [11, 10, 9, 8, 7, 6]
                       
                    ]
);
