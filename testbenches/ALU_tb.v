// apparently verilator isn't good at measuring delay at all,
// so these metrics are kinda useless rn other than pass or fail
// it'll be better on a pipeline/processor level though
module ALU_tb;
    reg [31:0] iDataA, iDataB;
    reg [3:0] iAluCtrl;
    wire [31:0] oData;
    wire oZero;

    ALU alu (.*);

    integer pass [0:15], fail [0:15];
    integer maskA, maskB;
    integer test, check_iter, display_op;

    task reset();
        iDataA = {32{1'b0}};
        iDataB = {32{1'b0}};
        iAluCtrl = {4{1'b0}};
        #10;
    endtask

    task random_test();
        reset();

        // done to get better spread of sizes, since nBits == delay in most cases
        maskA = (1 <<< ($random % 32)) - 1'b1;
        maskB = (1 <<< ($random % 32)) - 1'b1;
        iDataA = $random & maskA;
        iDataB = $random & maskB;
        iAluCtrl = $random[3:0];
        // while (iAluCtrl == 4'b0101) begin
        //     iAluCtrl = $random[3:0];
        // end

        check();
    endtask

    task check();
        integer expData;
        reg expZero;

        expData = 
            iAluCtrl == 4'b0000 ? iDataA + iDataB :
            iAluCtrl == 4'b0101 ? iDataA * iDataB :
            iAluCtrl == 4'b0001 ? iDataA << iDataB[4:0] :
            iAluCtrl == 4'b1001 ? iDataA >> iDataB[4:0] :
            // there's some weird stuff with signed precedence that's
            // causing this to fail, will fix it later
            // update: i never fixed it
            iAluCtrl == 4'b1101 ? $signed(iDataA) >>> iDataB[4:0] :
            iAluCtrl == 4'b0010 ? {{31{1'b0}}, $signed(iDataA) < $signed(iDataB)} :
            iAluCtrl == 4'b0011 ? {{31{1'b0}}, iDataA < iDataB} :
            iAluCtrl == 4'b0100 ? iDataA ^ iDataB :
            iAluCtrl == 4'b0110 ? iDataA | iDataB :
            iAluCtrl == 4'b0111 ? iDataA & iDataB :
            iDataA - iDataB;
        
        expZero =
            iAluCtrl == 4'b1010 ? $signed(iDataA) < $signed(iDataB) :
            iAluCtrl == 4'b1110 ? $signed(iDataA) > $signed(iDataB) :
            iAluCtrl == 4'b1011 ? iDataA < iDataB :
            iAluCtrl == 4'b1111 ? iDataA > iDataB :
            expData == 32'b0 ? 1'b1 : 1'b0;
        expZero = (iAluCtrl == 4'b1100 ? ~expZero : expZero);

        #1;

        if ((oData !== expData) || (oZero !== expZero)) begin
            fail[iAluCtrl] = fail[iAluCtrl] + 1;
            $display(
"Failure for iAluCtrl %b\
iDataA = %d, iDataB = %d\
got      -> oData = %d, oZero = %d\
expected -> oData = %d, oZero = %d",
                iAluCtrl, iDataA, iDataB, oData, oZero, expData, expZero
            );
        end else begin
            pass[iAluCtrl] = pass[iAluCtrl] + 1;
        end
    endtask

    task display_results();
        $display("----- ALU TEST RESULTS -----\n");
        for (display_op = 0; display_op <= 4'b1111; display_op = display_op + 1) begin
            $display("iAluCtrl %b: %3d passed, %3d failed", display_op[3:0], pass[display_op], fail[display_op]);
        end
    endtask

    initial begin
        for (test = 0; test < 500; test = test + 1) begin
            random_test();
        end

        display_results();
    end
endmodule