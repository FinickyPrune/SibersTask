//
//  ViewController.swift
//  Raccoon
//
//  Created by stajer on 23.04.2021.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet private weak var mainTable: UITableView!
    @IBOutlet private weak var addNewButton: UIButton!
    
    private var tableData: [Int] = []
    private let dataSize = 100
    
    private let cellIdentifier = "DefaultCell"
    private let addNewbuttonTitle = "Add New"
    private let tableName = "Table"
    
    private var isEditingCell = false
    private var pressedCellIndexPath = IndexPath(row: 0, section: 0)
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title  = tableName
        mainTable.dataSource = self
        mainTable.delegate = self
        
        mainTable.register(UITableViewCell.self, forCellReuseIdentifier: cellIdentifier)
        tableData = (0..<dataSize).map{_ in Int.random(in: 0..<100)}
        
        addNewButton.setTitle(addNewbuttonTitle, for: .normal)
        
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
    }
    
    @IBAction func buttonDidPressed(_ sender: Any?) {
        
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        if let viewController = storyboard.instantiateViewController(identifier: "EditorViewController") as? EditorViewController {
            isEditingCell = false
            viewController.delegate = self
            navigationController?.pushViewController(viewController, animated: true)
        }
    }
    
}

extension ViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return tableData.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier, for: indexPath)
        cell.textLabel?.text = String(tableData[indexPath.row])
        return cell
    }
}

extension ViewController: UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        if let viewController = storyboard.instantiateViewController(identifier: "EditorViewController") as? EditorViewController {
            isEditingCell = true
            pressedCellIndexPath = indexPath
            viewController.delegate = self
            navigationController?.pushViewController(viewController, animated: true)
            viewController.setNumberInputValue(value: tableData[indexPath.row])
        }
        
    }
    
    func tableView(_ tableView: UITableView, leadingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        
        let deleteAction = UIContextualAction(style: .destructive, title: "Delete", handler: {
            (deleteAction, tableView, false) -> Void in
            self.tableData.remove(at: indexPath.row)
            self.mainTable.reloadData()
        }
        )
        
        let configuration = UISwipeActionsConfiguration(actions: [deleteAction])
        configuration.performsFirstActionWithFullSwipe = false
        return configuration
    }  
}

extension ViewController: EditorDelegate {
    
    func didSubmit(_ sender: EditorViewController, value: Int) {
        
        if (isEditingCell) {
            tableData[pressedCellIndexPath.row] = value
            mainTable.reloadRows(at: [pressedCellIndexPath], with: .automatic)
            sender.navigationController?.popViewController(animated: true)
        }
        else {
            tableData.insert(value, at: 0)
            mainTable.insertRows(at: [IndexPath(row: 0, section: 0)], with: .automatic)
            sender.navigationController?.popViewController(animated: true)
        }
    }
}

