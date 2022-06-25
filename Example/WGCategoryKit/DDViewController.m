//
//  DDViewController.m
//  WGCategoryKit
//
//  Created by apple_dboy on 06/21/2022.
//  Copyright (c) 2022 apple_dboy. All rights reserved.
//

#import "DDViewController.h"
#import "UMLog.h"
#import  "UMAccount.h"


@interface DDViewController ()

@end

@implementation DDViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    NSString *version = [UMLogClient version];
    NSLog(@"log client version = %@", version);
    
    
    NSString *web_version = [UMWebClient version];
    NSLog(@"log client web_version = %@", web_version);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
