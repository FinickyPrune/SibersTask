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
    
    //private var tableData: [Int] = []
    //private let dataSize = 100
    private var viewModel: ViewModel = ViewModel()
    
    private let cellIdentifier = "DefaultCell"
    private let addNewbuttonTitle = "Add New"
    private let tableName = "Table"
    
    private var isEditingCell = false
    private var pressedCellIndexPath: IndexPath?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title  = tableName
        mainTable.dataSource = self
        mainTable.delegate = self
        
        mainTable.register(UITableViewCell.self, forCellReuseIdentifier: cellIdentifier)
        //tableData = (0..<dataSize).map{_ in Int.random(in: 0..<100)}
        addNewButton.setTitle(addNewbuttonTitle, for: .normal)
        
    }
    
    @IBAction private func buttonDidPressed(_ sender: Any?) {
        isEditingCell = false
        createEditorController(withOldValue: false)
    }
    
    private func createEditorController(withOldValue flag: Bool ) {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        if let viewController = storyboard.instantiateViewController(identifier: "EditorViewController") as? EditorViewController {
            viewController.delegate = self
            navigationController?.pushViewController(viewController, animated: true)
            if flag {
                guard let indexPath = pressedCellIndexPath else {
                    return
                }
                viewController.setNumberInputValue(value: viewModel.tableData[indexPath.row])
            }
        }
    }
    
}

extension ViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return viewModel.tableData.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier, for: indexPath)
        cell.textLabel?.text = viewModel.getStringValue(at: indexPath.row)
        return cell
    }
    
}

extension ViewController: UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        isEditingCell = true
        pressedCellIndexPath = indexPath
        createEditorController(withOldValue: true)
    }
    
    func tableView(_ tableView: UITableView, trailingSwipeActionsConfigurationForRowAt indexPath: IndexPath) -> UISwipeActionsConfiguration? {
        let deleteAction = UIContextualAction(style: .destructive, title: "Delete", handler: {
            (_, _, completion) in
            self.viewModel.deleteCellFromData(at: indexPath.row)
            self.mainTable.deleteRows(at: [indexPath], with: .right)
         })
        
        let configuration = UISwipeActionsConfiguration(actions: [deleteAction])
        configuration.performsFirstActionWithFullSwipe = false
        return configuration
    }  
}

extension ViewController: EditorDelegate {
    
    func didSubmit(_ sender: EditorViewController, value: Int) {
        if (isEditingCell) {
            guard let indexPath = pressedCellIndexPath else {
                return
            }
            viewModel.updateCellInData(at: indexPath.row, with: value)
            mainTable.reloadRows(at: [indexPath], with: .automatic)
            sender.navigationController?.popViewController(animated: true)
        }
        else {
            viewModel.insertCellInData(at: 0, with: value)
            mainTable.insertRows(at: [IndexPath(row: 0, section: 0)], with: .automatic)
            sender.navigationController?.popViewController(animated: true)
        }
    }
    
}

