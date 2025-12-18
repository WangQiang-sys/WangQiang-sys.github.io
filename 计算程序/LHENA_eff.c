void LHENA_eff() {
    // 数据
    const int n = 5;
    double x[n] = {2.3, 2.15, 2.0, 1.85, 1.7};       // 质子能量 (MeV)
    double y[n] = {16.30, 16.33, 16.37, 16.37, 16.39}; // 效率 (%)
    double ey[n] = {0.23, 0.23, 0.23, 0.31, 0.31};    // 效率误差 (y轴误差)
    
    // 创建图形和画布
    TCanvas *c1 = new TCanvas("c1", "Proton Energy vs Efficiency", 800, 600);
    
    // 创建带误差的图形（x轴误差设为nullptr，因为不需要）
    TGraphErrors *gr = new TGraphErrors(n, x, y, nullptr, ey); // 注意这里x轴误差设为nullptr
    gr->SetTitle("Efficiency vs Proton Energy");
    gr->GetXaxis()->SetTitle("Proton Energy (MeV)");
    gr->GetXaxis()->CenterTitle(true);
    gr->GetYaxis()->SetTitle("Efficiency (%)");
    gr->GetYaxis()->CenterTitle(true);
    gr->SetMarkerStyle(20);  // 圆形点
    gr->SetMarkerSize(1.2);
    gr->SetMarkerColor(kBlue);
    gr->SetLineColor(kBlue);
    gr->GetYaxis()->SetRangeUser(11, 21); 
    
    // 绘制图形
    gr->Draw("AP");
    
    // // 添加额外的标签
    // TLatex latex;
    // latex.SetNDC();
    // latex.SetTextSize(0.03);
    // latex.DrawLatex(0.15, 0.85, "Efficiency Measurement");
    
    // 更新画布
    c1->Update();
    
    // 保存为图片
    // c1->SaveAs("efficiency_vs_energy.png");
}