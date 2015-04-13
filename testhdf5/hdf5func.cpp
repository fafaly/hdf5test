#include "stdafx.h"
#include "hdf5func.h"

const int RANK = 1;

void AppendComData(H5::DataSet &dataset, Market_Data &value,DataType &mtype) {
	// dataspace
	hsize_t dims[RANK] = { 1 };
	hsize_t maxdims[RANK] = { H5S_UNLIMITED };
	H5::DataSpace mspace(RANK, dims, maxdims);

	H5::DataSpace space = dataset.getSpace();
	const hsize_t actual_dim = space.getSimpleExtentNpoints();

	// extend the dataset
	hsize_t new_size[RANK];
	new_size[0] = actual_dim + 1;
	dataset.extend(new_size);

	// select hyperslab.
	H5::DataSpace fspace = dataset.getSpace();
	hsize_t offset[RANK] = { actual_dim };
	hsize_t dims1[RANK] = { 1 };
	fspace.selectHyperslab(H5S_SELECT_SET, dims1, offset);

	dataset.write(&value, mtype, mspace, fspace);
}

int CreateGroup(const char * FILE_NAME, const char* groupname)
{
	//const H5std_string FILE_NAME("h5_dset.h5");
	// Try block to detect exceptions raised by any of the calls inside it
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately
		Exception::dontPrint();

		// Create a new file using default property lists.
		H5File file(FILE_NAME, H5F_ACC_RDWR);

		// Create a group named "/MygGroup" in the file
		Group group(file.createGroup(groupname));


		// File and group will be closed as their instances go out of scope.

	} // end of try block

	// catch failure caused by the H5File operations
	catch (FileIException error)
	{
		error.printError();
		return -1;
	}
	// catch failure caused by the Group operations
	catch (GroupIException error)
	{
		error.printError();
		return -1;
	}
	return 0;  // successfully terminated
}


/*
* Create groups in a file using absolute and relative paths
*/
int CreateGroupPar()
{

	const char*	 FILE_NAME("cfL2.h5");
	// Try block to detect exceptions raised by any of the calls inside it
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately.

		Exception::dontPrint();

		// Create a new file using default properties.

		H5File file(FILE_NAME, H5F_ACC_TRUNC);

		// Create group "MyGroup" in the root group using an absolute name.

		Group group1(file.createGroup("/SH_L2_market_data"));
		// Create group "Group_A" in group "MyGroup" using an
		// absolute name.

		Group group2(file.createGroup("/MyGroup/Group_A"));

		// Create group "Group_B" in group "MyGroup" using a
		// relative name.

		Group group3(group1.createGroup("Group_B"));

		// Close the groups and file.

		group1.close();
		group2.close();
		group3.close();
		file.close();

	} // end of try block

	// catch failure caused by the File operations
	catch (FileIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the Group operations
	catch (GroupIException error)
	{
		error.printError();
		return -1;
	}

	return 0;
}

void ReadDataSet(DataSet &dataset,DataType &mtype)
{
	/*
	* Read field b from s1 dataset. Field in the file is found by its name.
	*/
	Market_Data md2[3];  // Third "structure" - used to read float field of s1
	dataset.read(&md2, mtype);
	/*
	* Display the field
	*/
	cout << endl << "Field market data : " << endl;
	for (int i = 0; i <6; i++)
		cout << md2[i].dte << endl;
	cout << endl;
}


int CreateDataSet(const char *FILE_NAME, const char* DATASET_NAME)
{

	int ret = 0;
	Market_Data md;
	md.dte = 20140114;
	md.tme = 43334422;
	md.pclse = 460000;//
	md.opn = 441100;//
	md.high = 480000;
	md.low = 410000;
	md.lastPx = 420000;
	md.volume = 421421214;
	md.value = 142421442;
	md.tcount = 2354;
	memset(md.ask, 0, sizeof(md.ask));
	memset(md.asize, 0, sizeof(md.asize));
	memset(md.bid, 0, sizeof(md.bid));
	memset(md.bsize, 0, sizeof(md.bsize));
	md.ask[0] = 320000;
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately
		//Exception::dontPrint();
		CompType mtype(sizeof(Market_Data));
		mtype.insertMember(MEMBER1, HOFFSET(Market_Data, dte), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER2, HOFFSET(Market_Data, tme), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER3, HOFFSET(Market_Data, pclse), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER4, HOFFSET(Market_Data, opn), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER5, HOFFSET(Market_Data, high), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER6, HOFFSET(Market_Data, low), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER7, HOFFSET(Market_Data, lastPx), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER8, HOFFSET(Market_Data, volume), PredType::NATIVE_B64);
		mtype.insertMember(MEMBER9, HOFFSET(Market_Data, value), PredType::NATIVE_B64);
		mtype.insertMember(MEMBER10, HOFFSET(Market_Data, tcount), PredType::NATIVE_INT);

		mtype.insertMember(MEMBER11, HOFFSET(Market_Data, ask[1]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER12, HOFFSET(Market_Data, ask[2]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER13, HOFFSET(Market_Data, ask[3]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER14, HOFFSET(Market_Data, ask[4]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER15, HOFFSET(Market_Data, ask[5]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER16, HOFFSET(Market_Data, ask[6]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER17, HOFFSET(Market_Data, ask[7]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER18, HOFFSET(Market_Data, ask[8]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER19, HOFFSET(Market_Data, ask[9]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER20, HOFFSET(Market_Data, ask[10]), PredType::NATIVE_INT);

		mtype.insertMember(MEMBER21, HOFFSET(Market_Data, asize[1]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER22, HOFFSET(Market_Data, asize[2]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER23, HOFFSET(Market_Data, asize[3]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER24, HOFFSET(Market_Data, asize[4]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER25, HOFFSET(Market_Data, asize[5]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER26, HOFFSET(Market_Data, asize[6]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER27, HOFFSET(Market_Data, asize[7]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER28, HOFFSET(Market_Data, asize[8]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER29, HOFFSET(Market_Data, asize[9]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER30, HOFFSET(Market_Data, asize[10]), PredType::NATIVE_UINT);

		mtype.insertMember(MEMBER31, HOFFSET(Market_Data, bid[1]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER32, HOFFSET(Market_Data, bid[2]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER33, HOFFSET(Market_Data, bid[3]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER34, HOFFSET(Market_Data, bid[4]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER35, HOFFSET(Market_Data, bid[5]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER36, HOFFSET(Market_Data, bid[6]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER37, HOFFSET(Market_Data, bid[7]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER38, HOFFSET(Market_Data, bid[8]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER39, HOFFSET(Market_Data, bid[9]), PredType::NATIVE_INT);
		mtype.insertMember(MEMBER40, HOFFSET(Market_Data, bid[10]), PredType::NATIVE_INT);

		mtype.insertMember(MEMBER41, HOFFSET(Market_Data, bsize[1]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER42, HOFFSET(Market_Data, bsize[2]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER43, HOFFSET(Market_Data, bsize[3]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER44, HOFFSET(Market_Data, bsize[4]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER45, HOFFSET(Market_Data, bsize[5]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER46, HOFFSET(Market_Data, bsize[6]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER47, HOFFSET(Market_Data, bsize[7]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER48, HOFFSET(Market_Data, bsize[8]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER49, HOFFSET(Market_Data, bsize[9]), PredType::NATIVE_UINT);
		mtype.insertMember(MEMBER50, HOFFSET(Market_Data, bsize[10]), PredType::NATIVE_UINT);

		// create dataset for doubles:
		H5File* file = new H5File(FILE_NAME, H5F_ACC_RDWR);
		hsize_t  dim[RANK] = { 0 };
		hsize_t   maxdims[RANK] = { H5S_UNLIMITED };
		DataSpace space(RANK, dim, maxdims);
		// enable chunking for this dataset
		H5::DSetCreatPropList cparms;
		hsize_t chunk_dims[RANK] = { 1 };
		cparms.setChunk(RANK, chunk_dims);
		DataSet dataset = file->createDataSet(DATASET_NAME, mtype, space, cparms);

		//AppendComData(dataset, md, mtype);

		//ReadDataSet(dataset, mtype);

	}
	catch (FileIException error)
	{
		error.printError();
		ret = -1;
	}
	catch (DataSetIException error)
	{
		error.printError();
		ret = -1;
	}
	catch (DataSpaceIException error)
	{
		error.printError();
		ret = -1;
	}
	return ret;
}


int WriteData(const char* FILE_NAME, const char* DATASET_NAME)
{
	Market_Data md;
	md.dte = 20140118;
	md.tme = 43334422;
	md.pclse=460000;//
	md.opn=441100;//
	md.high=480000;
	md.low=410000;
	md.lastPx=420000;
	md.volume=421421214;
	md.value=142421442;
	md.tcount=2354;
	memset(md.ask, 0, sizeof(md.ask));
	memset(md.asize, 0, sizeof(md.asize));
	memset(md.bid, 0, sizeof(md.bid));
	memset(md.bsize, 0, sizeof(md.bsize));
	md.ask[0] = 320000;

	// Try block to detect exceptions raised by any of the calls inside it
	try
	{

		// update the file
		H5File* file = new H5File(FILE_NAME, H5F_ACC_RDWR);
		DataSet dataset = file->openDataSet(FILE_NAME);
		CompType mtype(dataset);
		AppendComData(dataset,md, mtype);
	//	AppendComData(dataset, md, mtype);
	//	AppendComData(dataset, md, mtype);
		////DataSpace space(rank, dim);
		///*
		//* Create the dataset.
		//*/
		//H5File* file = new H5File(FILE_NAME, H5F_ACC_RDWR);
		///*
		//* Modify dataset creation properties, i.e. enable chunking.
		//*/
		///*DSetCreatPropList cparms;
		//hsize_t      chunk_dims[1] = { 1 };
		//cparms.setChunk(rank, chunk_dims);*/
		///*
		//* Set fill value for the dataset
		//*/
		//
		////cparms.setFillValue(mtype, &md);
		//const DataSet* dataset;
		////dataset = new DataSet(file->createDataSet(DATASET_NAME,mtype,space));

		//dataset = new DataSet(file->openDataSet(DATASET_NAME));
		//CompType mtype(*dataset);
		///*
		//* Write data to the dataset;
		//*/
		////dataset->write(&md, mtype);

		//hsize_t size[1] = {1 };
		//dataset->extend(size);
		//md.dte = 20111101;
		//dataset->write(&md, mtype);


		/*
		* Release resources
		*/
		//delete dataset;
		delete file;
		ReadDataSet(dataset, mtype);
		//dataset.write(data, PredType::NATIVE_INT);

	}  // end of try block

	// catch failure caused by the H5File operations
	catch (FileIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the DataSet operations
	catch (DataSetIException error)
	{
		error.printError();
		return -1;
	}
	return 0;  // successfully terminated
}

int CreateAttribute()
{
	const H5std_string	FILE_NAME("h5tutr_dset.h5");
	const H5std_string	DATASET_NAME("dset");
	const H5std_string	ATTR_NAME("Units");

	const int	DIM1 = 2;

	int attr_data[2] = { 100, 200 };
	hsize_t dims[1] = { DIM1 };


	// Try block to detect exceptions raised by any of the calls inside it
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately
		Exception::dontPrint();

		// Open an existing file and dataset.
		H5File file(FILE_NAME, H5F_ACC_RDWR);
		DataSet dataset = file.openDataSet(DATASET_NAME);

		// Create the data space for the attribute.
		DataSpace attr_dataspace = DataSpace(1, dims);

		// Create a dataset attribute. 
		Attribute attribute = dataset.createAttribute(ATTR_NAME, PredType::STD_I32BE,
			attr_dataspace);

		// Write the attribute data. 
		attribute.write(PredType::NATIVE_INT, attr_data);

	}  // end of try block

	// catch failure caused by the H5File operations
	catch (DataSpaceIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the H5File operations
	catch (AttributeIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the H5File operations
	catch (FileIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the DataSet operations
	catch (DataSetIException error)
	{
		error.printError();
		return -1;
	}
	return 0;  // successfully terminated
}


/*I
* Create a file and dataset and select/read a subset from the dataset
*/
int SubSet()
{
	const char*	FILE_NAME("h5tutr_subset.h5");
	const H5std_string	DATASET_NAME("IntArray");

	const int     RANK = 2;
	const int     DIM0_SUB = 3;	// subset dimensions
	const int     DIM1_SUB = 4;
	const int     DIM0 = 8;		// size of dataset
	const int     DIM1 = 10;
	int     i, j;
	int     data[DIM0][DIM1], sdata[DIM0_SUB][DIM1_SUB], rdata[DIM0][DIM1];

	// Try block to detect exceptions raised by any of the calls inside it
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately
		Exception::dontPrint();

		// ---------------------------------------------------
		// Create a new file using the default property lists. 
		// Then create a dataset and write data to it. 
		// Close the file and dataset.
		// ---------------------------------------------------

		H5File file(FILE_NAME, H5F_ACC_TRUNC);

		hsize_t dims[2];
		dims[0] = DIM0;
		dims[1] = DIM1;
		DataSpace dataspace = DataSpace(RANK, dims);

		DataSet dataset(file.createDataSet(DATASET_NAME,
			PredType::STD_I32BE, dataspace));

		for (j = 0; j < DIM0; j++) {
			for (i = 0; i < DIM1; i++)
			if (i< (DIM1 / 2))
				data[j][i] = 1;
			else
				data[j][i] = 2;
		}

		dataset.write(data, PredType::NATIVE_INT);

		cout << endl << "Data Written to File:" << endl;
		for (j = 0; j < DIM0; j++) {
			for (i = 0; i < DIM1; i++)
				cout << " " << data[j][i];
			cout << endl;
		}

		dataspace.close();
		dataset.close();
		file.close();

		// ---------------------------------------------------
		// Reopen the file and dataset and write a subset of
		// values to the dataset.
		// ---------------------------------------------------

		hsize_t offset[2], count[2], stride[2], block[2];
		hsize_t dimsm[2];

		file.openFile(FILE_NAME, H5F_ACC_RDWR);
		dataset = file.openDataSet(DATASET_NAME);

		// Specify size and shape of subset to write. 

		offset[0] = 1;
		offset[1] = 2;

		count[0] = DIM0_SUB;
		count[1] = DIM1_SUB;

		stride[0] = 1;
		stride[1] = 1;

		block[0] = 1;
		block[1] = 1;

		// Define Memory Dataspace. Get file dataspace and select
		// a subset from the file dataspace.

		dimsm[0] = DIM0_SUB;
		dimsm[1] = DIM1_SUB;

		DataSpace memspace(RANK, dimsm, NULL);

		dataspace = dataset.getSpace();
		dataspace.selectHyperslab(H5S_SELECT_SET, count, offset, stride, block);

		// Write a subset of data to the dataset, then read the
		// entire dataset back from the file.

		cout << endl << "Write subset to file specifying: " << endl;
		cout << "  offset=1x2 stride=1x1 count=3x4 block=1x1" << endl;
		for (j = 0; j < DIM0_SUB; j++) {
			for (i = 0; i < DIM1_SUB; i++)
				sdata[j][i] = 5;
		}

		dataset.write(sdata, PredType::NATIVE_INT, memspace, dataspace);
		dataset.read(rdata, PredType::NATIVE_INT);


		cout << endl << "Data in File after Subset is Written:" << endl;
		for (i = 0; i < DIM0; i++) {
			for (j = 0; j < DIM1; j++)
				cout << " " << rdata[i][j];
			cout << endl;
		}
		cout << endl;

		// It is not necessary to close these objects because close() will
		// be called when the object instances are going out of scope.
		dataspace.close();
		memspace.close();
		dataset.close();
		file.close();

	}  // end of try block

	// catch failure caused by the H5File operations
	catch (FileIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the DataSet operations
	catch (DataSetIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the DataSpace operations
	catch (DataSpaceIException error)
	{
		error.printError();
		return -1;
	}

	return 0;  // successfully terminated
}

/*
* Create a chunked and compressed dataset
*/
int CreateExtend()
{
	const H5std_string	FILE_NAME("h5tutr_extend.h5");
	const H5std_string	DATASETNAME("ExtendibleArray");

	hsize_t dims[2] = { 3, 3 };	        // dataset dimensions at creation
	hsize_t maxdims[2] = { H5S_UNLIMITED, H5S_UNLIMITED };
	hsize_t chunk_dims[2] = { 2, 5 };
	int	   data[3][3] = { { 1, 1, 1 },    // data to write 
	{ 1, 1, 1 },
	{ 1, 1, 1 } };

	// Variables used in extending and writing to the extended portion of dataset 

	hsize_t size[2];
	hsize_t offset[2];
	hsize_t dimsext[2] = { 7, 3 };         // extend dimensions 
	int     dataext[7][3] = { { 2, 3, 4 },
	{ 2, 3, 4 },
	{ 2, 3, 4 },
	{ 2, 3, 4 },
	{ 2, 3, 4 },
	{ 2, 3, 4 },
	{ 2, 3, 4 } };

	// Try block to detect exceptions raised by any of the calls inside it
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately
		Exception::dontPrint();

		// Create a new file using the default property lists. 
		H5File file(FILE_NAME, H5F_ACC_TRUNC);

		// Create the data space for the dataset.  Note the use of pointer
		// for the instance 'dataspace'.  It can be deleted and used again
		// later for another dataspace.  An HDF5 identifier can be closed
		// by the destructor or the method 'close()'.
		DataSpace *dataspace = new DataSpace(2, dims, maxdims);

		// Modify dataset creation property to enable chunking
		DSetCreatPropList prop;
		prop.setChunk(2, chunk_dims);

		// Create the chunked dataset.  Note the use of pointer.
		DataSet *dataset = new DataSet(file.createDataSet(DATASETNAME,
			PredType::STD_I32BE, *dataspace, prop));

		// Write data to dataset.
		dataset->write(data, PredType::NATIVE_INT);

		// Extend the dataset. Dataset becomes 10 x 3.
		size[0] = dims[0] + dimsext[0];
		size[1] = dims[1];
		dataset->extend(size);

		// Select a hyperslab in extended portion of the dataset.
		DataSpace *filespace = new DataSpace(dataset->getSpace());
		offset[0] = 3;
		offset[1] = 0;
		filespace->selectHyperslab(H5S_SELECT_SET, dimsext, offset);

		// Define memory space.
		DataSpace *memspace = new DataSpace(2, dimsext, NULL);

		// Write data to the extended portion of the dataset.
		dataset->write(dataext, PredType::NATIVE_INT, *memspace, *filespace);

		// Close all objects and file.
		prop.close();
		delete filespace;
		delete memspace;
		delete dataspace;
		delete dataset;
		file.close();

		// --------------------------------------- 
		// Re-open the file and read the data back
		// --------------------------------------- 

		int        rdata[10][3];
		int        i, j, rank, rank_chunk;
		hsize_t    chunk_dimsr[2], dimsr[2];

		// Open the file and dataset.
		file.openFile(FILE_NAME, H5F_ACC_RDONLY);
		dataset = new DataSet(file.openDataSet(DATASETNAME));

		// Get the dataset's dataspace and creation property list.
		filespace = new DataSpace(dataset->getSpace());
		prop = dataset->getCreatePlist();

		// Get information to obtain memory dataspace.
		rank = filespace->getSimpleExtentNdims();
		herr_t status_n = filespace->getSimpleExtentDims(dimsr);

		if (H5D_CHUNKED == prop.getLayout())
			rank_chunk = prop.getChunk(rank, chunk_dimsr);
		cout << "rank chunk = " << rank_chunk << endl;;

		memspace = new DataSpace(rank, dimsr, NULL);
		dataset->read(rdata, PredType::NATIVE_INT, *memspace, *filespace);

		cout << endl;
		for (j = 0; j < dimsr[0]; j++) {
			for (i = 0; i < dimsr[1]; i++)
				cout << " " << rdata[j][i];
			cout << endl;
		}

		// Close all objects and file.
		prop.close();
		delete filespace;
		delete memspace;
		delete dataset;
		file.close();

	}  // end of try block

	// catch failure caused by the H5File operations
	catch (FileIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the DataSet operations
	catch (DataSetIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the DataSpace operations
	catch (DataSpaceIException error)
	{
		error.printError();
		return -1;
	}

	return 0;  // successfully terminated
}

/*
* Create a chunked and compressed dataset
*/
int CreateChunk()
{
	const H5std_string	FILE_NAME("h5tutr_cmprss.h5");
	const H5std_string	DATASET_NAME("Compressed_Data");
	const int	DIM0 = 100;
	const int	DIM1 = 20;

	hsize_t dims[2] = { DIM0, DIM1 };	// dataset dimensions
	hsize_t chunk_dims[2] = { 20, 20 };	// chunk dimensions
	int     i, j, buf[DIM0][DIM1];

	// Try block to detect exceptions raised by any of the calls inside it
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately
		Exception::dontPrint();

		// Create a new file using the default property lists. 
		H5File file(FILE_NAME, H5F_ACC_TRUNC);

		// Create the data space for the dataset.
		DataSpace *dataspace = new DataSpace(2, dims);

		// Modify dataset creation property to enable chunking
		DSetCreatPropList  *plist = new  DSetCreatPropList;
		plist->setChunk(2, chunk_dims);

		// Set ZLIB (DEFLATE) Compression using level 6.
		// To use SZIP compression comment out this line.
		plist->setDeflate(6);

		// Uncomment these lines to set SZIP Compression
		// unsigned szip_options_mask = H5_SZIP_NN_OPTION_MASK;
		// unsigned szip_pixels_per_block = 16;
		// plist->setSzip(szip_options_mask, szip_pixels_per_block);

		// Create the dataset.      
		DataSet *dataset = new DataSet(file.createDataSet(DATASET_NAME,
			PredType::STD_I32BE, *dataspace, *plist));

		for (i = 0; i< DIM0; i++)
		for (j = 0; j<DIM1; j++)
			buf[i][j] = i + j;

		// Write data to dataset.
		dataset->write(buf, PredType::NATIVE_INT);

		// Close objects and file.  Either approach will close the HDF5 item.
		delete dataspace;
		delete dataset;
		delete plist;
		file.close();

		// -----------------------------------------------
		// Re-open the file and dataset, retrieve filter 
		// information for dataset and read the data back.
		// -----------------------------------------------

		int        rbuf[DIM0][DIM1];
		int        numfilt;
		size_t     nelmts = { 1 }, namelen = { 1 };
		unsigned  flags, filter_info, cd_values[1], idx;
		char       name[1];
		H5Z_filter_t filter_type;

		// Open the file and the dataset in the file.
		file.openFile(FILE_NAME, H5F_ACC_RDONLY);
		dataset = new DataSet(file.openDataSet(DATASET_NAME));

		// Get the create property list of the dataset.
		plist = new DSetCreatPropList(dataset->getCreatePlist());

		// Get the number of filters associated with the dataset.
		numfilt = plist->getNfilters();
		cout << "Number of filters associated with dataset: " << numfilt << endl;

		for (idx = 0; idx < numfilt; idx++) {
			nelmts = 0;

			filter_type = plist->getFilter(idx, flags, nelmts, cd_values, namelen, name, filter_info);

			cout << "Filter Type: ";

			switch (filter_type) {
			case H5Z_FILTER_DEFLATE:
				cout << "H5Z_FILTER_DEFLATE" << endl;
				break;
			case H5Z_FILTER_SZIP:
				cout << "H5Z_FILTER_SZIP" << endl;
				break;
			default:
				cout << "Other filter type included." << endl;
			}
		}

		// Read data.
		dataset->read(rbuf, PredType::NATIVE_INT);

		delete plist;
		delete dataset;
		file.close();	// can be skipped

	}  // end of try block

	// catch failure caused by the H5File operations
	catch (FileIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the DataSet operations
	catch (DataSetIException error)
	{
		error.printError();
		return -1;
	}

	// catch failure caused by the DataSpace operations
	catch (DataSpaceIException error)
	{
		error.printError();
		return -1;
	}

	return 0;  // successfully terminated
}

