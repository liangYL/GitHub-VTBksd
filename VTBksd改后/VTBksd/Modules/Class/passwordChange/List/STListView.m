//
//  STListView.m
//  VTBksd
//
//  Created by steve on 14/10/28.
//  Copyright (c) 2014年 GK. All rights reserved.
//

#import "STListView.h"

@implementation STListView

-(void)startLoad
{
    [super startLoad];
    
    __block typeof(self) this = self;
    
    VTDevDataChannelDocData *docData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *cData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:docData];
    cData.name = ((XCForm *)[self.autoLayout getFormById:@"list"].view).viewDef.rootBlock.tableName;
    NSDictionary *dic = _parametersDic;
    cData.simplecondition = [NSMutableArray arrayWithObject:dic];
    
    [super getData:docData xform:@"list" result:^(id obj){
        [this.autoLayout loadFormView:@"list"];
        [this.autoLayout settingOutlet:this];
        [[XCControlKitUtil getBlock:this.tableView] getData];
    }error:nil];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [[XCControlKitUtil getBlock:tableView].data count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static  NSString *str =@"cell";
    
    XCSuperModuleCell *cell =[tableView dequeueReusableCellWithIdentifier:str];
    if (cell ==nil)
    {
        cell =[[[XCSuperModuleCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:str] autorelease];
        cell.css = self.cellCss;
        [cell startLoad];
        cell.backgroundColor = [UIColor clearColor];
    }
    XCDataBlock *block = [XCControlKitUtil getBlock:tableView];
    [block.aClass dataImmit:[block.data objectAtIndex:indexPath.row] views:cell.autoLayout.views map:nil filter:nil imageFilter:^(XCAutoLayout *layout, NSString *key, NSString *value, id imageView) {
        
        [imageView loadUrl:VImageUrl(value) placeholderImage:[UIImage imageNamed:@"homeImage.png"]];
    }];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    XCDataBlock *block = [XCControlKitUtil getBlock:tableView];
    id obj = [block.data objectAtIndex:indexPath.row];
    [block setCurrentRow:@{@"key":@"_id",@"value":[obj objectForKey:@"_id"]}];
    
    
    XCSendEvent(STListViewCellClick,[self.autoLayout.root.blocks objectForKey:@"tableViewCell"]);
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return self.cellHeight;
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    
    if (editingStyle == UITableViewCellEditingStyleDelete)
    {
        [self deleteAddress:indexPath];
    }
}

- (void)pullTableViewPullLoad:(XCPullTableView *)tableView
{
    __block typeof(self) this = self;
    
    VTDevDataChannelDocData *docData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *cData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:docData];
    cData.name = ((XCForm *)[self.autoLayout getFormById:@"list"].view).viewDef.rootBlock.tableName;
    NSDictionary *dic = _parametersDic;
    cData.simplecondition = [NSMutableArray arrayWithObject:dic];
    
    [super getDataReload:docData xform:@"list" result:^(id obj){
        [[XCControlKitUtil getBlock:this.tableView] getData];
        [this.tableView reloadData];
    }error:^(id aError) {
        
    }];
}

- (void)pullTableViewMoreLoad:(XCPullTableView *)tableView
{
    __block typeof(self) this = self;
    
    VTDevDataChannelDocData *docData = [[VTDataParamsFactory shardParamsFactory] getDataParams];
    VTDevDataChannelDocConditionsData *cData = [[VTDataParamsFactory shardParamsFactory] getDataConditions:docData];
    cData.name = ((XCForm *)[self.autoLayout getFormById:@"list"].view).viewDef.rootBlock.tableName;
    NSDictionary *dic = _parametersDic;
    cData.simplecondition = [NSMutableArray arrayWithObject:dic];
    
    [super getDataAppend:docData xform:@"list" result:^(id obj){
        [[XCControlKitUtil getBlock:this.tableView] getData];
        [this.tableView reloadData];
    }error:^(id aError) {
        
    }];
}

//滑动删除
- (void)deleteAddress:(NSIndexPath *)indexPath
{
    id obj = [[XCControlKitUtil getBlock:self.tableView].data objectAtIndex:indexPath.row];
    NSMutableDictionary *dic = [NSMutableDictionary dictionaryWithObject:[obj objectForKey:@"_id"] forKey:@"_id"];
    
    [[XCControlKitUtil getBlock:self.tableView] addCurd:dic flag:2 indexPath:[NSIndexPath indexPathForRow:0 inSection:0]];
    VTDevDataChannelDocUpdateData *cData = [[VTDataParamsFactory shardParamsFactory] getUpdataParams:[XCControlKitUtil getBlock:self.tableView].getCurd];
    
    [super upData:cData xform:[XCControlKitUtil getBlock:self.tableView].dataView.form result:^(id obj){
        
        [self.hud showOKHud:@"删除成功" delay:2];
        
        [[XCControlKitUtil getBlock:self.tableView].data removeObjectAtIndex:indexPath.row];
        [self.tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationFade];
        
        XCSendEvent(STListViewCellDeleteSucceed, @"1");
        
    } error:^(id  error){
        
        [self.hud showNOHud:@"删除失败!" delay:2];
        
        XCSendEvent(STListViewCellDeleteSucceed, @"0");
        
    }];
}

@end
